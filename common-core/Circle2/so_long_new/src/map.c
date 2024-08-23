/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:17:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/23 15:19:53 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	parse_map(t_game *game, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Error while opening file\n", -1, game, NULL);
	game->map.grid = ft_calloc(sizeof(char *), (game->height + 1));
	if (!game->map.grid)
		handle_error("Error while allocating memory to grid", 0, NULL, NULL);
	i = 0;
	line = gnl_newline(fd);
	while (line)
	{
		game->map.grid[i] = ft_strdup(line);
		free(line);
		line = gnl_newline(fd);
		i++;
	}
	free(line);
	close(fd);
	game->map.grid[i] = NULL;
}

t_img	*get_tile(t_game *game, char tile)
{
	if (tile == WALL)
		return (&game->wall);
	else if (tile == FLOOR)
		return (&game->floor);
	else if (tile == COLLECTIBLE)
		return (&game->collectible);
	else if (tile == EXIT)
		return (&game->exit);
	else if (tile == PLAYER)
		return (&game->player);
	return (NULL);
}

int	render_map(t_game *game)
{
	int		i;
	int		j;
	t_img	*img;

	i = 0;
	draw_base(game);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			img = get_tile(game, game->map.grid[i][j]);
			if (!img)
				handle_error("Invalid tile in map\n", -1, game, NULL);
			draw_img(game, img, i, j);
			blend_transparency(game, img, j * TILESIZE, i * TILESIZE);
			j++;
		}
		i++;
	}
	return (0);
}
