/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:59:48 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/17 14:55:18 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	exit_process(t_pipex *pipex, char *msg)
{
	if (pipex->infile > 0)
	{
		if (pipex->is_here_doc)
		{
			unlink(pipex->here_doc);
			free(pipex->here_doc);
		}
		close(pipex->infile);
	}
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

void	init_pipex(t_pipex *pipex, int ac)
{
	pipex->env = NULL;
	pipex->paths = NULL;
	pipex->here_doc = NULL;
	pipex->is_here_doc = 0;
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->cmds = NULL;
	pipex->cmd_start = 2;
	pipex->cmd_end = ac - 2;
}
