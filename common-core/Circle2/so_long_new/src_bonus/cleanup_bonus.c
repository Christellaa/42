/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:30:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/26 09:35:46 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	handle_error(char *msg, int fd, t_game *game_free, char **to_free)
{
	ft_printf(msg);
	if (fd)
		close(fd);
	if (game_free)
		free(game_free);
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
