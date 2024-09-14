/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:06:35 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/14 18:40:13 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	wait_pids(t_cmd *cmd)
{
	int	status_info;
	int	exit_code;

	exit_code = -1;
	while (errno != ECHILD && cmd)
	{
		if (waitpid(cmd->pid, &status_info, WNOHANG) != -1)
		{
			if (WIFEXITED(status_info))
				exit_code = WEXITSTATUS(status_info);
			else
				exit_code = 128 + WTERMSIG(status_info);
		}
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
		if (tmp->name != NULL)
			tmp->pid = child(tmp, pipex);
		tmp = tmp->next;
	}
	pid_status = wait_pids(pipex->cmds);
	free_cmds(pipex->cmds);
	free_groups(pipex->paths);
	if (pipex->is_here_doc)
	{
		unlink(pipex->here_doc);
		free(pipex->here_doc);
	}
	return (pid_status);
}

void	parent(int ac, char **av, t_pipex *pipex)
{
	if (pipex->is_here_doc)
	{
		check_files(ac, 6, 2, pipex);
		name_here_doc(pipex);
		if (!pipex->here_doc)
			exit_process(pipex, NULL, "Name_here_doc");
		pipex->infile = handle_here_doc(av[2], pipex);
		pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		check_files(ac, 5, 1, pipex);
		pipex->infile = open(av[1], O_RDONLY);
		pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (pipex->infile < 0)
		print_msg(av[1]);
	if (pipex->outfile < 0)
		print_msg(av[ac - 1]);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	t_cmd	*cmds;

	init_pipex(&pipex);
	if (ac > 1 && ft_strequ(av[1], "here_doc"))
		pipex.is_here_doc = 1;
	parent(ac, av, &pipex);
	pipex.env = env;
	av[ac - 1] = NULL;
	pipex.paths = get_paths(env);
	if (pipex.is_here_doc)
		cmds = get_cmds(&av[3], pipex.paths);
	else
		cmds = get_cmds(&av[2], pipex.paths);
	pipex.cmds = cmds;
	return (children(&pipex));
}
