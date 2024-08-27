/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:56:13 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/27 15:54:31 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_msg(char *msg, char *exit_type)
{
	char	*color;

	if (ft_strncmp(msg, ERROR, 5) == 0)
		color = RED;
	else
		color = YELLOW;
	ft_printf("%s%s: %s\n%s", color, exit_type, msg, RESET);
}

void	exit_program(t_pipex *pipex, char *msg, char *exit_type)
{
	if (pipex)
	{
		if (pipex->envp)
			free(pipex->envp);
		if (pipex->is_here_doc == 1)
		{
			//free(pipex->here_doc);
			unlink(pipex->here_doc);
			pipex->here_doc = NULL;
		}
		if (pipex->infile > 0)
			close(pipex->infile);
		if (pipex->outfile > 0)
			close(pipex->outfile);
	}
	print_msg(msg, exit_type);
	if (ft_strncmp(exit_type, ERROR, 5) == 0)
		exit(EXIT_FAILURE);
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
			i++;
		}
		free(group1);
	}
	i = 0;
	if (group2)
	{
		while (group2[i])
		{
			free(group2[i]);
			i++;
		}
		free(group2);
	}
}

void	close_here_doc(t_pipex pipex)
{
	if (pipex.is_here_doc == 1)
	{
		close(pipex.infile);
		unlink(pipex.here_doc);
	}
}
