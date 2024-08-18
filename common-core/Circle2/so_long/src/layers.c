/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:48:56 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/15 19:06:18 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	alloc_layer(t_map *map, int i)
{
	int	current_row;

	current_row = 0;
	map->layers[i]->tiles = malloc(map->rows * sizeof(char *));
	if (!map->layers[i]->tiles)
		handle_error("malloc layer tiles", -1, NULL, NULL);
	while (current_row < map->rows)
	{
		map->layers[i]->tiles[current_row] = malloc((map->cols + 1) * \
		sizeof(char));
		if (!map->layers[i]->tiles[current_row])
			handle_error("malloc layer row", -1, map->layers[i]->tiles, \
			NULL);
		current_row++;
	}
	return (0);
}

int	assign_to_layer(char c, int row, int col, t_map *map)
{
	if (c == FLOOR)
		map->layers[0]->tiles[row][col] = FLOOR;
	if (c == WALL)
		map->layers[1]->tiles[row][col] = WALL;
	if (c == COLLECTIBLE)
	{
		check_char(c, map);
		map->layers[1]->tiles[row][col] = COLLECTIBLE;
	}
	if (c == EXIT)
	{
		check_char(c, map);
		map->layers[1]->tiles[row][col] = EXIT;
	}
	if (c == PLAYER)
	{
		check_char(c, map);
		map->layers[2]->tiles[row][col] = PLAYER;
	}
	else
		return (1);
	return (0);
}

int	load_layers(int fd, t_map *map)
{
	char	*line;
	int		current_row;
	int		current_col;
	char	c;

	current_row = 0;
	while (current_row < map->rows)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		current_col = 0;
		while (current_col < map->cols)
		{
			c = line[current_col];
			assign_to_layer(c, current_row, current_col, map);
			current_col++;
		}
		free(line);
		current_row++;
	}
	return (0);
}
