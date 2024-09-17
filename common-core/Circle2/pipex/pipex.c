/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:06:35 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/17 14:09:14 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_pids(t_cmd *cmd)
{
	int	status_info;
	int	exit_code;

	exit_code = 0;
	while (errno != ECHILD && cmd && waitpid(cmd->pid, &status_info, 0) != -1)
	{
		if (WIFEXITED(status_info))
			exit_code = WEXITSTATUS(status_info);
		cmd = cmd->next;
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
	pid_status = wait_pids(pipex->cmds);
	free_cmds(pipex->cmds);
	free_groups(pipex->paths);
	return (pid_status);
}

void	parent(int ac, char **av, t_pipex *pipex)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
		print_msg(av[1]);
	pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		print_msg(av[ac - 1]);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	t_cmd	*cmds;

	init_pipex(&pipex);
	if (ac != 5)
	{
		ft_printf("%s\n", USAGE);
		exit_process(&pipex, NULL);
	}
	pipex.env = env;
	parent(ac, av, &pipex);
	av[ac - 1] = NULL;
	pipex.paths = get_paths(env);
	cmds = get_cmds(&av[2], pipex.paths);
	pipex.cmds = cmds;
	return (children(&pipex));
}
