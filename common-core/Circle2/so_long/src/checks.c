/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:33:59 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/18 20:40:38 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_elements(char c, t_map *map)
{
	if (c == PLAYER)
		map->validator.p_count++;
	if (c == EXIT)
		map->validator.e_count++;
	// . check if map is playable (player can go to both collectibles and exit)
	// after rendering whole map
	if (c == COLLECTIBLE)
		map->validator.c_count++;
	return (0);
}

int	validate_elements(t_map map)
{
	if (map.validator.p_count != 1)
		handle_error("Too many players or no player\n", -1, NULL, NULL);
	if (map.validator.e_count != 1)
		handle_error("Too many exits or no exit\n", -1, NULL, NULL);
	if (map.validator.c_count < 1)
		handle_error("Not enough collectibles\n", -1, NULL, NULL);
	return (0);
}

int	check_map_edges(t_map map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < map.rows)
	{
		if (map.layers[1]->tiles[row][0] != WALL || \
		map.layers[1]->tiles[row][map.cols - 1] != WALL)
			handle_error("Map not surrounded by walls\n", -1, NULL, NULL);
		row++;
	}
	while (col < map.cols)
	{
		if (map.layers[1]->tiles[0][col] != WALL || \
		map.layers[1]->tiles[map.rows - 1][col] != WALL)
			handle_error("Map not surrounded by walls\n", -1, NULL, NULL);
		col++;
	}
	if (map.cols > col)
		handle_error("Not all lines are the same length\n", -1, NULL, NULL);
	return (0);
}

void	explore_map(t_game *game, int x, int y, \
		int visited[game->map.rows][game->map.cols])
{
	if (x <= 0 || y <= 0 || x >= game->map.cols || y >= game->map.rows || \
	game->map.layers[1]->tiles[y][x] == WALL || \
	game->map.layers[1]->tiles[y][x] == VISITED)
		return ;
	if (game->map.layers[1]->tiles[y][x] == COLLECTIBLE)
		game->map.validator.c_reachable++;
	else if (game->map.layers[1]->tiles[y][x] == EXIT)
		game->map.validator.e_reachable = 1;
	visited[y][x] = 1;
	explore_map(game, x + 1, y, visited);
	explore_map(game, x - 1, y, visited);
	explore_map(game, x, y + 1, visited);
	explore_map(game, x, y - 1, visited);
}

int	check_playability(t_game game)
{
	int	x;
	int	y;
	int	visited;

	visited[game.map.rows][game.map.cols];

	x = game.player_x;
	y = game.player_y;
	ft_memset(visited, 0, sizeof(visited));
	explore_map(&game, x, y, visited);
	if (game.map.validator.e_reachable != 1 || \
	game.map.validator.c_reachable != game.map.validator.c_count)
		handle_error("Not all collectibles or the exit are reachable\n", -1, \
		NULL, NULL);
	return (0);
}
