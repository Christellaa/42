/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:48:56 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/18 20:34:13 by cde-sous         ###   ########.fr       */
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

int	assign_to_layer(char c, int row, int col, t_game *game)
{
	if (c == FLOOR)
		game->map.layers[0]->tiles[row][col] = FLOOR;
	else if (c == WALL)
		game->map.layers[1]->tiles[row][col] = WALL;
	else if (c == COLLECTIBLE)
		game->map.layers[1]->tiles[row][col] = COLLECTIBLE;
	else if (c == EXIT)
		game->map.layers[1]->tiles[row][col] = EXIT;
	else if (c == PLAYER)
	{
		game->map.layers[2]->tiles[row][col] = PLAYER;
		game->player_x = col;
		game->player_y = row;
	}
	else
		return (1);
	check_elements(c, &game->map);
	return (0);
}

int	load_layers(int fd, t_game *game)
{
	char	*line;
	int		current_row;
	int		current_col;
	char	c;

	current_row = 0;
	while (current_row < game->map.rows)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		current_col = 0;
		while (current_col < game->map.cols)
		{
			c = line[current_col];
			assign_to_layer(c, current_row, current_col, game);
			current_col++;
		}
		free(line);
		current_row++;
	}
	return (0);
}
