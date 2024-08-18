/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:05:48 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/07 16:02:16 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_child(char **av, char **paths, t_pipex pipex)
{
	char	*path;
	char	**args;

	args = ft_split(av[pipex.current_cmd], ' ');
	if (!args)
		handle_error("split args", NULL, 0, 0);
	path = find_cmd_path(args[0], paths);
	if (!path)
	{
		free_group(args);
		free_group(paths);
		handle_error("find command path", NULL, 0, 0);
	}
	if (execve(path, args, pipex.envp) == -1)
	{
		free_group(args);
		free_group(paths);
		handle_error("execve", path, 0, 0);
	}
}

void	child(char **av, char **paths, t_pipex pipex)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		handle_error("pipe", NULL, 0, 0);
	pid = fork();
	if (pid < 0)
		handle_error("fork", NULL, pipefd[0], pipefd[1]);
	else if (pid == 0)
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			handle_error("dup2 fd[1]", NULL, pipefd[1], 0);
		close(pipefd[1]);
		exec_child(av, paths, pipex);
	}
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		handle_error("dup2 fd[0]", NULL, pipefd[0], 0);
	close(pipefd[0]);
	waitpid(-1, NULL, WNOHANG);
}

void	parent(int ac, char **av, t_pipex *pipex)
{
	if (pipex->is_here_doc == 1)
	{
		check_files(ac, 6, 2, av);
		pipex->inputfile = get_files(av, 1, 2);
		pipex->outputfile = get_files(av, ac - 1, 3);
		if (pipex->outputfile < 0)
		{
			unlink("here_doc");
			handle_error("open outfile", NULL, 0, pipex->outputfile);
		}
		pipex->current_cmd = 3;
	}
	else
	{
		check_files(ac, 5, 1, av);
		pipex->inputfile = get_files(av, 1, 0);
		pipex->outputfile = get_files(av, ac - 1, 1);
		if (pipex->outputfile < 0)
			handle_error("open outfile", NULL, 0, pipex->outputfile);
		pipex->current_cmd = 2;
	}
	if (dup2(pipex->inputfile, STDIN_FILENO) == -1)
		handle_error("dup2 inputfile", NULL, 0, 0);
	close(pipex->inputfile);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	char	**paths;

	if (ac > 1 && ft_strequ(av[1], "here_doc"))
		pipex.is_here_doc = 1;
	else
		pipex.is_here_doc = 0;
	parent(ac, av, &pipex);
	if (dup2(pipex.outputfile, STDOUT_FILENO) == -1)
		handle_error("dup2 outputfile", NULL, 0, 0);
	close(pipex.outputfile);
	pipex.nb_cmd = count_cmd(ac, av);
	pipex.envp = env;
	paths = get_paths(pipex);
	if (!paths)
		handle_error("find paths", NULL, pipex.inputfile, pipex.outputfile);
	while (pipex.current_cmd < ac - 2)
	{
		child(av, paths, pipex);
		pipex.current_cmd++;
	}
	exec_child(av, paths, pipex);
	free_group(paths);
	exit(EXIT_SUCCESS);
}
