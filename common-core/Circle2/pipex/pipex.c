/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:26:23 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/23 10:46:12 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_child(char *cmd, char **paths, t_pipex pipex)
{
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
		handle_error("Error: split arguments", NULL, pipex.infile, \
		pipex.outfile);
	path = find_cmd_path(args[0], paths);
	if (!path)
	{
		free_group(args, paths);
		handle_error("Error: find command path", NULL, pipex.infile, \
		pipex.outfile);
	}
	if (execve(path, args, pipex.envp) == -1)
	{
		free_group(args, paths);
		handle_error("Error: execute execve", path, pipex.infile, \
		pipex.outfile);
	}
}

void	child(char *cmd, char **paths, t_pipex pipex)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		handle_error("Error: pipe", NULL, 0, 0);
	pid = fork();
	if (pid < 0)
		handle_error("Error: fork", NULL, pipefd[0], pipefd[1]);
	else if (pid == 0)
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			handle_error("Error: dup2 fd[1]", NULL, pipefd[1], 0);
		close(pipefd[1]);
		close(pipex.outfile);
		exec_child(cmd, paths, pipex);
	}
	close(pipefd[1]);
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
		handle_error("Error: dup2 fd[0]", NULL, pipefd[0], 0);
	close(pipex.infile);
}

void	parent(int ac, char **av, t_pipex *pipex)
{
	if (ac != 5)
	{
		ft_printf("Usage: %s infile cmd1 cmd2 outfile\n", av[0]);
		exit(EXIT_FAILURE);
	}
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
		handle_error("Error: open infile", NULL, -1, -1);
	pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		handle_error("Error: open outfile", NULL, pipex->infile, -1);
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
		handle_error("Error: dup2 infile", NULL, pipex->infile, pipex->outfile);
	close(pipex->infile);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	char	**paths;

	parent(ac, av, &pipex);
	pipex.envp = env;
	paths = get_paths(pipex);
	if (!paths)
		handle_error("Error: get paths", NULL, pipex.infile, pipex.outfile);
	child(av[2], paths, pipex);
	if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
		handle_error("Error: dup2 outfile", NULL, pipex.infile, pipex.outfile);
	close(pipex.outfile);
	exec_child(av[3], paths, pipex);
	free_group(paths, NULL);
	exit(EXIT_FAILURE);
}
