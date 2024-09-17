/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:59:48 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/17 14:00:15 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_groups(char **groups)
{
	int	i;

	if (!groups)
		return ;
	i = 0;
	while (groups[i])
	{
		free(groups[i]);
		groups[i] = NULL;
		++i;
	}
	free(groups);
	groups = NULL;
}

void	free_cmds(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp->name);
		free_groups(tmp->args);
		free(tmp);
	}
}

void	print_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	if (errno)
	{
		write(2, ": ", 2);
		perror("");
	}
}

void	exit_process(t_pipex *pipex, t_cmd *cmds, char *msg)
{
	(void)cmds;
	if (pipex->infile > 0)
		close(pipex->infile);
	if (pipex->outfile > 0)
		close(pipex->outfile);
	if (pipex->cmds)
		free_cmds(pipex->cmds);
	if (pipex->paths)
		free_groups(pipex->paths);
	if (msg)
		print_msg(msg);
	exit(127);
}

void	init_pipex(t_pipex *pipex)
{
	pipex->env = NULL;
	pipex->paths = NULL;
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->cmds = NULL;
}
