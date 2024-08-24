/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:33:00 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/24 11:09:07 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	check_params(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width - 1)
		{
			if (!ft_strchr("01CEPMO", game->map.grid[i][j]))
			{
				handle_error("Invalid map parameters\n", 0, NULL, NULL);
			}
			if (game->map.grid[i][j] == PLAYER)
				game->map.validator.p_count++;
			if (game->map.grid[i][j] == EXIT)
				game->map.validator.e_count++;
			if (game->map.grid[i][j] == COLLECTIBLE)
				game->map.validator.c_count++;
			j++;
		}
		i++;
	}
}

void	check_map_edges(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (game->map.grid[i][0] != WALL \
			|| game->map.grid[i][game->width - 1] != WALL)
			handle_error("Map is not closed by walls\n", -1, game, NULL);
		i++;
	}
	i = 0;
	while (i < game->width)
	{
		if (game->map.grid[0][i] != WALL \
			|| game->map.grid[game->height - 1][i] != WALL)
			handle_error("Map is not closed by walls\n", -1, NULL, NULL);
		i++;
	}
}

void	check_map_rectangular(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map.grid[i][j] == '\0')
				handle_error("Map is not rectangular\n", -1, game, NULL);
			j++;
		}
		if (j != game->width)
			handle_error("Map is not rectangular\n", -1, game, NULL);
		i++;
	}
	if (i != game->height)
		handle_error("Map is not rectangular\n", -1, game, NULL);
}

int	check_map_validity(t_game *game)
{
	check_params(game);
	if (game->map.validator.p_count != 1)
		handle_error("Player count is not valid\n", -1, game, NULL);
	if (game->map.validator.e_count != 1)
		handle_error("Exit count is not valid\n", -1, game, NULL);
	if (game->map.validator.c_count < 1)
		handle_error("Collectible count is not valid\n", -1, game, NULL);
	check_map_edges(game);
	check_reachability(game);
	if (game->map.validator.e_reachable == 0)
		handle_error("Exit is not reachable\n", -1, game, NULL);
	if (game->map.validator.c_reachable != game->map.validator.c_count)
		handle_error("Collectibles are not reachable\n", -1, game, NULL);
	check_map_rectangular(game);
	return (0);
}
