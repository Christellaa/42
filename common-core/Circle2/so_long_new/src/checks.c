/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:33:00 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/20 16:16:12 by cde-sous         ###   ########.fr       */
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
		while (j < game->width)
		{
			if (!ft_strchr("01CEPMO", game->map.grid[i][j]))
				handle_error("Invalid map parameters\n", -1, game, NULL);
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
	if (game->map.grid[0][0] != WALL \
		|| game->map.grid[0][game->width - 1] != WALL
		|| game->map.grid[game->height - 1][0] != WALL
		|| game->map.grid[game->height - 1][game->width - 1] != WALL)
		handle_error("Map is not closed by walls\n", -1, game, NULL);
}

void	check_reachability(t_game *game, int i, int j)
{
	if (i < 0 || i >= game->height || j < 0 || j >= game->width)
		return ;
	if (game->map.grid[i][j] == WALL || game->map.grid[i][j] == OBSTACLE)
		return ;
	if (game->map.grid[i][j] == EXIT)
		game->map.validator.e_reachable = 1;
	if (game->map.grid[i][j] == COLLECTIBLE)
		game->map.validator.c_reachable++;
	game->map.grid[i][j] = OBSTACLE;
	check_reachability_recursive(game, i - 1, j);
	check_reachability_recursive(game, i + 1, j);
	check_reachability_recursive(game, i, j - 1);
	check_reachability_recursive(game, i, j + 1);
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
	check_reachability(game, game->player.x, game->player.y);
	if (game->map.validator.e_reachable == 0)
		handle_error("Exit is not reachable\n", -1, game, NULL);
	if (game->map.validator.c_reachable != game->map.validator.c_count)
		handle_error("Collectible is not reachable\n", -1, game, NULL);
	check_map_rectangular(game);
	return (0);
}
