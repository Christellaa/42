/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:33:59 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/15 19:14:14 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_char(char c, t_map *map)
{
	if (c == PLAYER)
	{
		map->validator.p_count++;
		if (map->validator.p_count > 1)
			handle_error("too many players", -1, NULL, NULL);
	}
	if (c == EXIT)
	{
		map->validator.e_count++;
		if (map->validator.e_count > 1)
			handle_error("too many exits", -1, NULL, NULL);
	}
	// . should check collectible nb after rendering whole map
	// . check if map is playable (player can go to both collectibles and exit)
	// after rendering whole map
	if (c == COLLECTIBLE)
	{
		map->validator.c_count++;
		if (map->validator.c_count < 1)
			handle_error("not enough collectibles", -1, NULL, NULL);
	}
	return (0);
}

int	check_map(t_map_validator validator)
{
	if (validator.p_count != 1 || validator.e_count != 1 || \
	validator.c_count < 1 || !validator.map_valid)
		return (1);
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
			handle_error("map not surrounded by walls", -1, NULL, NULL);
		row++;
	}
	while (col < map.cols)
	{
		if (map.layers[1]->tiles[0][col] != WALL || \
		map.layers[1]->tiles[map.rows - 1][col] != WALL)
			handle_error("map not surrounded by walls", -1, NULL, NULL);
		col++;
	}
	return (0);
}
