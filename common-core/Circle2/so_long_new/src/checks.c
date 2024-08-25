/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:33:00 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/25 22:08:47 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
			if (!ft_strchr("01CEP", game->map.grid[i][j]))
				exit_game(game, "Invalid character in map\n", ERROR);
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
			exit_game(game, "Map is not closed by walls\n", ERROR);
		i++;
	}
	i = 0;
	while (i < game->width)
	{
		if (game->map.grid[0][i] != WALL \
			|| game->map.grid[game->height - 1][i] != WALL)
			exit_game(game, "Map is not closed by walls\n", ERROR);
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
				exit_game(game, "Map is not rectangular\n", ERROR);
			j++;
		}
		if (j != game->width)
			exit_game(game, "Map is not rectangular\n", ERROR);
		i++;
	}
	if (i != game->height)
		exit_game(game, "Map is not rectangular\n", ERROR);
}

int	check_map_validity(t_game *game)
{
	check_params(game);
	if (game->map.validator.p_count != 1)
		exit_game(game, "Player count is not valid\n", ERROR);
	if (game->map.validator.e_count != 1)
		exit_game(game, "Exit count is not valid\n", ERROR);
	if (game->map.validator.c_count < 1)
		exit_game(game, "Collectible count is not valid\n", ERROR);
	check_map_edges(game);
	check_reachability(game);
	if (game->map.validator.e_reachable == 0)
		exit_game(game, "Exit is not reachable\n", ERROR);
	if (game->map.validator.c_reachable != game->map.validator.c_count)
		exit_game(game, "Collectibles are not reachable\n", ERROR);
	check_map_rectangular(game);
	return (0);
}
