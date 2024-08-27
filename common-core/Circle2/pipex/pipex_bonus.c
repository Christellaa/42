/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:05:48 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/27 16:38:21 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_child(char **av, char **paths, t_pipex pipex)
{
	char	*path;
	char	**args;

	args = ft_split(av[pipex.current_cmd], ' ');
	if (!args)
		exit_program(&pipex, "split command", ERROR);
	path = find_cmd_path(&pipex, args[0], paths);
	if (!path)
	{
		free_groups(args, paths);
		exit_program(&pipex, "find command path", ERROR);
	}
	if (execve(path, args, pipex.envp) == -1)
	{
		free_groups(args, paths);
		exit_program(&pipex, "execute execve", ERROR);
	}
}

void	child(char **av, char **paths, t_pipex pipex)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		exit_program(&pipex, "create pipe", ERROR);
	pid = fork();
	if (pid < 0)
		exit_program(&pipex, "fork child process", ERROR);
	else if (pid == 0)
	{
		//if (av[1] || else) - > dup2(file || pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		//if (ac - 2 || else) - > dup2(file || pipefd[1], STDOUT_FILENO);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			exit_program(&pipex, "dup2 pipefd[1]", ERROR);
		close(pipefd[1]);
		exec_child(av, paths, pipex);
	}
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		exit_program(&pipex, "dup2 pipefd[0]", ERROR);
	close(pipefd[0]);
	// wait(-1)
	waitpid(-1, NULL, WNOHANG);
}

void	parent(int ac, char **av, t_pipex *pipex)
{
	if (pipex->is_here_doc == 1)
	{
		pipex->here_doc = name_here_doc(pipex);
		check_files(ac, 6, 2, pipex);
		pipex->infile = get_files(av, 1, 2, pipex);
		pipex->outfile = get_files(av, ac - 1, 3, pipex);
		if (pipex->outfile < 0)
			exit_program(pipex, "open outfile", ERROR);
		pipex->current_cmd = 3;
	}
	else
	{
		check_files(ac, 5, 1, pipex);
		pipex->infile = get_files(av, 1, 0, pipex);
		pipex->outfile = get_files(av, ac - 1, 1, pipex);
		if (pipex->outfile < 0)
			exit_program(pipex, "open outfile", ERROR);
		pipex->current_cmd = 2;
	}
	//if (dup2(pipex->infile, STDIN_FILENO) == -1)
	//	exit_program(pipex, "dup2 infile", ERROR);
	close(pipex->infile);
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
	//if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
	//	exit_program(&pipex, "dup2 outfile", ERROR);
	close(pipex.outfile);
	pipex.nb_cmd = count_cmd(&pipex, ac, av);
	pipex.envp = env;
	paths = get_paths(pipex);
	if (!paths)
		exit_program(&pipex, "get paths", ERROR);
	while (pipex.current_cmd < ac - 2)
	{
		child(av, paths, pipex);
		pipex.current_cmd++;
	}
	close_here_doc(pipex);
	exec_child(av, paths, pipex);
	exit(EXIT_FAILURE);
}
