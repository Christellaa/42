/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:56:13 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/31 13:14:06 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_msg(char *msg, char *exit_type)
{
	/* char	*color;
	//char	*err;

	color = RESET;
	if (ft_strncmp(exit_type, ERROR, 5) == 0)
	{
		color = RED;
		ft_printf("AAAAAA");
		perror(msg);
		//ft_printf("%s%s: %s\n%s", color, exit_type, err, RESET);
	}
	else if (ft_strncmp(exit_type, INFO, 4) == 0)
		color = YELLOW;
	ft_printf("%s%s: %s\n%s", color, exit_type, msg, RESET);
	else */
	(void)exit_type;
	perror(msg);
}

void	exit_program(t_pipex *pipex, char *msg, char *exit_type)
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
