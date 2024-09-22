/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:06:35 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/22 15:05:23 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	wait_pids(void)
{
	int	status_info;
	int	exit_code;

	exit_code = 0;
	while (errno != ECHILD && waitpid(-1, &status_info, 0) != -1)
	{
		if (WIFEXITED(status_info))
			exit_code = WEXITSTATUS(status_info);
	}
	return (exit_code);
}

int	children(t_pipex *pipex)
{
	int		pid_status;
	t_cmd	*tmp;

	tmp = pipex->cmds;
	create_pipes(tmp);
	while (tmp)
	{
		tmp->pid = child(tmp, pipex);
		tmp = tmp->next;
	}
	tmp = pipex->cmds;
	close_fds(tmp, pipex);
	pid_status = wait_pids();
	free_cmds(pipex->cmds);
	free_groups(pipex->paths);
	if (pipex->is_here_doc)
	{
		unlink(pipex->here_doc);
		free(pipex->here_doc);
	}
	if (pipex->outfile < 0)
		pid_status = 1;
	return (pid_status);
}

void	parent(int ac, char **av, t_pipex *pipex)
{
	if (pipex->is_here_doc)
	{
		check_files(ac, 6, 2, pipex);
		name_here_doc(pipex);
		pipex->infile = handle_here_doc(av[2], pipex);
		pipex->outfile = open_fd(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, \
		1, pipex);
	}
	else
	{
		check_files(ac, 5, 1, pipex);
		pipex->infile = open_fd(av[1], O_RDONLY, 1, pipex);
		pipex->outfile = open_fd(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, \
		2, pipex);
	}
	if (pipex->infile < 0)
		pipex->cmd_start++;
	if (pipex->outfile < 0)
		pipex->cmd_end--;
	if (pipex->cmd_end < pipex->cmd_start)
		exit_process(pipex, NULL);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	t_cmd	*cmds;

	init_pipex(&pipex, ac);
	if (ac > 1 && ft_strequ(av[1], "here_doc"))
	{
		pipex.is_here_doc = 1;
		pipex.cmd_start++;
	}
	parent(ac, av, &pipex);
	pipex.env = env;
	av[ac - 1] = NULL;
	pipex.paths = get_paths(env);
	cmds = get_cmds(&av[pipex.cmd_start], pipex.paths, &pipex);
	pipex.cmds = cmds;
	return (children(&pipex));
}
