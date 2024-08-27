/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:26:23 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/27 16:56:55 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_child(char *cmd, char **paths, t_pipex pipex)
{
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
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

void	child(char *cmd, char **paths, t_pipex pipex)
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
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			exit_program(&pipex, "dup2 pipefd[1]", ERROR);
		close(pipefd[1]);
		close(pipex.outfile);
		exec_child(cmd, paths, pipex);
	}
	close(pipefd[1]);
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
		exit_program(&pipex, "dup2 infile", ERROR);
	close(pipex.infile);
}

void	parent(int ac, char **av, t_pipex *pipex)
{
	if (ac != 5)
		exit_program(pipex, USAGE, INFO);
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
		exit_program(pipex, "open infile", ERROR);
	pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		exit_program(pipex, "open outfile", ERROR);
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
		exit_program(pipex, "dup2 infile", ERROR);
	close(pipex->infile);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	char	**paths;

	ft_memset(&pipex, 0, sizeof(t_pipex));
	parent(ac, av, &pipex);
	pipex.envp = env;
	paths = get_paths(pipex);
	if (!paths)
		exit_program(&pipex, "get paths", ERROR);
	child(av[2], paths, pipex);
	if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
		exit_program(&pipex, "dup2 outfile", ERROR);
	close(pipex.outfile);
	exec_child(av[3], paths, pipex);
	exit(EXIT_FAILURE);
}
