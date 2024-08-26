/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:17:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/26 11:47:24 by cde-sous         ###   ########.fr       */
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
		exit_game(game, "Unable to open map file\n", ERROR);
	game->map.grid = ft_calloc(sizeof(char *), (game->height + 1));
	if (!game->map.grid)
	{
		close(fd);
		exit_game(game, "Unable to allocate memory to grid\n", ERROR);
	}
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
	{
		if (game->map.validator.c_count == 0)
			return (&game->exit_open);
		else
			return (&game->exit_close);
	}
	else if (tile == PLAYER)
	{
		if (game->player_pos.direction == 1)
			return (&game->player_left);
		if (game->player_pos.direction == 2)
			return (&game->player_up);
		if (game->player_pos.direction == 3)
			return (&game->player_right);
		if (game->player_pos.direction == 4)
			return (&game->player_down);
	}
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
			{
				ft_printf("tile: %c\n", game->map.grid[i][j]);
				exit_game(game, "Invalid map tile\n", ERROR);
			}
			draw_img(game, img, i, j);
			blend_transparency(game, img, j * TILESIZE, i * TILESIZE);
			j++;
		}
		i++;
	}
	return (0);
}
