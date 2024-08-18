/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:26:23 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/07 17:04:53 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_child(char *cmd, char **paths, t_pipex pipex)
{
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
		handle_error("split args", NULL, pipex.inputfile, pipex.outputfile);
	path = find_cmd_path(args[0], paths);
	if (!path)
	{
		free_group(args, paths);
		handle_error("find command path", NULL, pipex.inputfile, \
					pipex.outputfile);
	}
	if (execve(path, args, pipex.envp) == -1)
	{
		free_group(args, paths);
		handle_error("execve", path, pipex.inputfile, pipex.outputfile);
	}
}

void	child(char *cmd, char **paths, t_pipex pipex)
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
		close(pipex.outputfile);
		exec_child(cmd, paths, pipex);
	}
	close(pipefd[1]);
	if (dup2(pipex.inputfile, STDIN_FILENO) == -1)
		handle_error("dup2 fd[0]", NULL, pipefd[0], 0);
	close(pipex.inputfile);
}

void	parent(int ac, char **av, t_pipex *pipex)
{
	if (ac != 5)
	{
		ft_printf("Usage: %s infile cmd1 cmd2 outfile\n", av[0]);
		exit(EXIT_FAILURE);
	}
	pipex->inputfile = open(av[1], O_RDONLY);
	if (pipex->inputfile < 0)
		handle_error("open infile", NULL, -1, -1);
	pipex->outputfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outputfile < 0)
		handle_error("open outfile", NULL, pipex->inputfile, -1);
	if (dup2(pipex->inputfile, STDIN_FILENO) == -1)
		handle_error("dup2 inputfile", NULL, pipex->inputfile, \
					pipex->outputfile);
	close(pipex->inputfile);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	char	**paths;

	parent(ac, av, &pipex);
	pipex.envp = env;
	paths = get_paths(pipex);
	if (!paths)
		handle_error("find paths", NULL, pipex.inputfile, pipex.outputfile);
	child(av[2], paths, pipex);
	if (dup2(pipex.outputfile, STDOUT_FILENO) == -1)
		handle_error("dup2 outputfile", NULL, pipex.inputfile, \
					pipex.outputfile);
	close(pipex.outputfile);
	exec_child(av[3], paths, pipex);
	free_group(paths, NULL);
	exit(EXIT_SUCCESS);
}
