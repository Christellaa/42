/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:29:07 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/18 20:28:35 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_map_dimensions(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		map->cols = ft_strlen(line) - 1;
		map->rows++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (map->cols == 0 || map->rows == 0)
		handle_error("Empty map\n", -1, NULL, NULL);
	return (0);
}

int	render_map(t_game *game)
{
	int		row;
	int		col;
	int		i;
	t_img	*tile;

	draw_base(game);
	row = 0;
	while (row < game->map.rows)
	{
		col = 0;
		while (col < game->map.cols)
		{
			i = 0;
			while (i < 3)
			{
				tile = get_tile(game, game->map.layers[i]->tiles[row][col]);
				draw_tile(game->map.layers[i]->tiles[row][col], row, col, game);
				blend_transparency(game, tile, col * TILESIZE, row * TILESIZE);
				i++;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	load_map(char *filename, t_game *game)
{
	int		fd;
	int		i;

	fd = open_or_reset_fd(-1, filename);
	get_map_dimensions(fd, &game->map);
	init_game(game);
	if (game->map.rows == 0 || game->map.cols == 0)
		return (1);
	i = 0;
	while (i < 3)
	{
		alloc_layer(&game->map, i);
		i++;
	}
	fd = open_or_reset_fd(fd, filename);
	load_layers(fd, &game);
	check_map_edges(game->map);
	validate_elements(game->map);
	check_playability(*game);
	ft_printf("Enter render_map\n");
	render_map(game);
	ft_printf("Leave render_map\n");
	close(fd);
	return (0);
}
