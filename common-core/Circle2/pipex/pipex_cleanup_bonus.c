/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:56:13 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/07 13:51:39 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	free_group(char **group)
{
	int	i;

	i = 0;
	if (group)
	{
		while (group[i])
		{
			free(group[i]);
			group[i] = NULL;
			i++;
		}
		free(group);
		group = NULL;
	}
}
