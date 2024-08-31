/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:05:48 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/31 12:37:33 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_child(char **av, char **paths, t_pipex pipex)
{
	char	*path;
	char	**args;

	args = ft_split(av[pipex.current_cmd], ' ');
	if (!args)
		print_msg("split args", ERROR);
	path = find_cmd_path(args[0], paths);
	if (!path)
	{
		free_groups(args, paths);
		exit_program(&pipex, "find cmd path", ERROR);
	}
	if (execve(path, args, pipex.envp) == -1)
	{
		free_groups(args, paths);
		exit_program(&pipex, "execve", ERROR);
	}
}

void	dup_files(t_pipex *pipex, int *pipefd)
{
	if ((pipex->is_here_doc == 0 && pipex->current_cmd == 2) \
		|| (pipex->is_here_doc == 1 && pipex->current_cmd == 3))
	{
		check_dup2(pipefd, pipex->infile, STDIN_FILENO, pipex);
	}
	else
		check_dup2(pipefd, pipefd[0], STDIN_FILENO, pipex);
	if (pipex->infile > 0)
		close(pipex->infile);
	close(pipefd[0]);
	if ((pipex->current_cmd == pipex->nb_cmd + 1 && pipex->is_in_out.out == 0) \
	|| (pipex->current_cmd == pipex->nb_cmd + 2 && pipex->is_in_out.out == 1))
	{
		check_dup2(pipefd, pipex->outfile, STDOUT_FILENO, pipex);
	}
	else
		check_dup2(pipefd, pipefd[1], STDOUT_FILENO, pipex);
	if (pipex->outfile > 0)
		close(pipex->outfile);
	close(pipefd[1]);
}

int	child(char **av, char **paths, t_pipex pipex)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		exit_program(&pipex, "create pipe", ERROR);
	pid = fork();
	if (pid < 0)
	{
		print_msg("fork child process", ERROR);
		return (0);
	}
	else if (pid == 0)
	{
		dup_files(&pipex, pipefd);
		exec_child(av, paths, pipex);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	return (1);
}

void	parent(int ac, char **av, t_pipex *pipex)
{
	if (pipex->is_here_doc == 1)
	{
		check_files(ac, 6, 2, pipex);
		name_here_doc(pipex);
		pipex->infile = get_files(av, 1, 2, pipex);
		pipex->outfile = get_files(av, ac - 1, 3, pipex);
	}
	else
	{
		check_files(ac, 5, 1, pipex);
		pipex->infile = get_files(av, 1, 0, pipex);
		pipex->outfile = get_files(av, ac - 1, 1, pipex);
	}
	if (pipex->infile < 0)
	{
		pipex->current_cmd++;
		pipex->is_in_out.in = 1;
		print_msg("infile", ERROR);
	}
	if (pipex->outfile < 0)
	{
		pipex->nb_cmd--;
		pipex->is_in_out.out = 1;
		print_msg("outfile", ERROR);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	char	**paths;

	ft_memset(&pipex, 0, sizeof(t_pipex));
	init_values(&pipex);
	if (ac > 1 && ft_strequ(av[1], "here_doc"))
		pipex.is_here_doc = 1;
	else
		pipex.is_here_doc = 0;
	pipex.nb_cmd = count_cmd(ac, av);
	parent(ac, av, &pipex);
	pipex.envp = env;
	paths = get_paths(pipex);
	if (!paths)
		print_msg("get paths", ERROR);
	while (pipex.current_cmd <= pipex.nb_cmd + 1)
	{
		child(av, paths, pipex);
		pipex.current_cmd++;
	}
	if (paths)
		free_groups(paths, NULL);
	while (wait(NULL) > 0)
		;
	exit_program(&pipex, "Success", INFO);
}
