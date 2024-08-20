/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:30:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/20 16:56:51 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_error(char *msg, int fd, t_game *game_free, char **to_free)
{
	ft_printf(msg);
	if (fd)
		close(fd);
	if (to_free)
		free(to_free);
	if (to_free)
		free_group(to_free);
	exit(EXIT_FAILURE);
}

void	free_group(char **group)
{
	int	i;

	i = 0;
	while (group[i])
		free(group[i++]);
	free(group);
}