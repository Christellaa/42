/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:56:13 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/23 11:19:53 by cde-sous         ###   ########.fr       */
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

void	close_here_doc(t_pipex pipex)
{
	if (pipex.is_here_doc == 1)
	{
		if (unlink(pipex.here_doc) != 0)
			handle_error("Error: unlink here_doc", NULL, 0, 0);
	}
}