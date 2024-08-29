/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:56:13 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/29 18:07:25 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_values(t_pipex *pipex)
{
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->envp = NULL;
	pipex->current_cmd = 2;
}

void	print_msg(char *msg, char *exit_type)
{
	char	*color;
	char	*err;

	color = RESET;
	if (ft_strncmp(exit_type, ERROR, 5) == 0)
	{
		color = RED;
		err = strerror(errno);
	}
	else if (ft_strncmp(exit_type, INFO, 4) == 0)
		color = YELLOW;
	if (ft_strncmp(exit_type, ERROR, 5) == 0 && errno != 0)
		ft_printf("%s%s: %s\n%s", color, exit_type, err, RESET);
	else
		ft_printf("%s%s: %s\n%s", color, exit_type, msg, RESET);
}

void	exit_program(t_pipex *pipex, char *msg, char *exit_type)
{
	if (pipex)
	{
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
