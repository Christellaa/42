/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:56:13 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/07 16:05:12 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_error(char *msg, char *to_free, int fd1, int fd2)
{
	if (msg)
		perror(msg);
	if (to_free)
		free(to_free);
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
	exit(EXIT_FAILURE);
}

void	free_group(char **group1, char **group2)
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
