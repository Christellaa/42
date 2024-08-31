/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:56:13 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/31 14:01:56 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_msg(char *msg)
{
	perror(msg);
}

void	exit_program(t_pipex *pipex, char *msg, int flag)
{
	if (pipex)
	{
		if (pipex->infile > 0)
		{
			close_here_doc(*pipex);
			close(pipex->infile);
		}
		if (pipex->outfile > 0)
			close(pipex->outfile);
	}
	if (flag == 1)
	{
		if (msg)
			print_msg(msg);
		exit(EXIT_FAILURE);
	}
	else if (flag == 0)
		exit(EXIT_SUCCESS);
}

void	free_groups(char **group1, char **group2)
{
	int	i;

	i = 0;
	if (group1)
	{
		while (group1[i])
		{
			free(group1[i]);
			group1[i++] = NULL;
		}
		free(group1);
		group1 = NULL;
	}
	i = 0;
	if (group2)
	{
		while (group2[i])
		{
			free(group2[i]);
			group2[i++] = NULL;
		}
		free(group2);
		group2 = NULL;
	}
}

void	close_here_doc(t_pipex pipex)
{
	if (pipex.is_here_doc == 1)
	{
		unlink(pipex.here_doc);
		free(pipex.here_doc);
	}
}
