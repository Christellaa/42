/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:30:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/19 12:11:51 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_error(char *msg, int fd, char **to_free, int **to_free2)
{
	ft_printf(msg);
	if (fd)
		close(fd);
	if (to_free)
		free_group_char(to_free);
	if (to_free2)
		free_group_int(to_free2);
	exit(EXIT_FAILURE);
}

void	free_group_char(char **group)
{
	int	i;

	i = 0;
	while (group[i])
		free(group[i++]);
	free(group);
}

void	free_group_int(int **group)
{
	int	i;

	i = 0;
	while (group[i])
		free(group[i++]);
	free(group);
}

int	open_or_reset_fd(int fd, char *filename)
{
	if (fd >= 0)
		close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("open file", -1, NULL, NULL);
	return (fd);
}
