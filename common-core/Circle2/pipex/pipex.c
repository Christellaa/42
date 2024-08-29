/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:05:48 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/29 17:49:08 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	dup_files(int ac, char **av, t_pipex *pipex, int *pipefd)
{
	if (av[1])
	{
		if (dup2(pipex->infile, STDIN_FILENO) == -1)
			exit_program(pipex, "dup2 infile", ERROR);
		close(pipex->infile);
	}
	else
	{
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			exit_program(pipex, "dup2 pipefd[0]", ERROR);
	}
	close(pipefd[0]);
	if (av[ac - 2])
	{
		if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
			exit_program(pipex, "dup2 outfile", ERROR);
		close(pipex->outfile);
	}
	else
	{
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			exit_program(pipex, "dup2 pipefd[1]", ERROR);
	}
	close(pipefd[1]);
}

void	child(int ac, char **av, char **paths, t_pipex pipex)
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
		dup_files(ac, av, &pipex, pipefd);
		exec_child(av, paths, pipex);
	}
	close(pipefd[0]);
	close(pipefd[1]);
}

void	parent(int ac, char **av, t_pipex *pipex)
{
	if (ac != 5)
		exit_program(pipex, USAGE, ERROR);
	pipex->infile = open(av[1], O_RDONLY);
	pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->infile < 0 || pipex->outfile < 0)
		exit_program(pipex, "open infile and outfile", ERROR);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	char	**paths;

	ft_memset(&pipex, 0, sizeof(t_pipex));
	init_values(&pipex);
	parent(ac, av, &pipex);
	pipex.envp = env;
	paths = get_paths(pipex);
	if (!paths)
		exit_program(&pipex, "get paths", ERROR);
	while (pipex.current_cmd < ac - 1)
	{
		child(ac, av, paths, pipex);
		pipex.current_cmd++;
	}
	free_groups(paths, NULL);
	while (wait(NULL) > 0)
		;
	exit_program(&pipex, "Success", INFO);
}
