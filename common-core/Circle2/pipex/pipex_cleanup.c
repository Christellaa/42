/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:56:13 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/27 16:57:28 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_msg(char *msg, char *exit_type)
{
	char	*color;
	char	*err;

	if (ft_strncmp(msg, ERROR, 5) == 0)
	{
		color = RED;
		err = strerror(errno);
	}
	else
		color = YELLOW;
	if (ft_strncmp(exit_type, ERROR, 5) == 0)
		ft_printf("%s%s: %s\n%s", color, exit_type, err, RESET);
	else if (ft_strncmp(exit_type, INFO, 4) == 0)
		ft_printf("%s%s: %s\n%s", color, exit_type, msg, RESET);
}

void	exit_program(t_pipex *pipex, char *msg, char *exit_type)
{
	if (pipex)
	{
		if (pipex->envp)
			free(pipex->envp);
		if (pipex->infile > 0)
			close(pipex->infile);
		if (pipex->outfile > 0)
			close(pipex->outfile);
	}
	print_msg(msg, exit_type);
	if (ft_strncmp(exit_type, ERROR, 5) == 0 \
	|| ft_strncmp(exit_type, INFO, 4) == 0)
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
