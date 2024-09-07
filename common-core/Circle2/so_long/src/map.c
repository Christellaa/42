/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:17:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/07 15:24:59 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	parse_map(t_game *game, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	fd = open_fd(game, filename);
	i = 0;
	line = gnl_newline(fd);
	while (line && line[0] != '\0' && line[0] != '\n')
	{
		game->map.grid = ft_realloc(game->map.grid, sizeof(char *) * i,
				sizeof(char *) * (i + 2));
		if (!game->map.grid)
			exit_game(game, "Unable to allocate memory to grid", ERROR);
		game->map.grid[i] = ft_strdup(line);
		free(line);
		if (i == 0)
			game->width = ft_strlen(game->map.grid[i]);
		game->height++;
		check_map_line(game, i);
		i++;
		line = gnl_newline(fd);
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

void	render_map(t_game *game)
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
				exit_game(game, "Invalid map tile", ERROR);
			draw_img(game, img, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->main_img.img_ptr, 0, 0);
}
