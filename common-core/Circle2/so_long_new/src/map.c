/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:17:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/22 18:23:40 by cde-sous         ###   ########.fr       */
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

void	draw_img(t_game *game, int i, int j)
{
	if (game->map.grid[i][j] == FLOOR)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, FLOOR_XPM, \
		j * TILESIZE, i * TILESIZE);
	else if (game->map.grid[i][j] == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, WALL_XPM, \
		j * TILESIZE, i * TILESIZE);
	else if (game->map.grid[i][j] == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, COLLECTIBLE_XPM, \
		j * TILESIZE, i * TILESIZE);
	else if (game->map.grid[i][j] == EXIT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, EXIT_XPM, \
		j * TILESIZE, i * TILESIZE);
	else if (game->map.grid[i][j] == PLAYER)
	{
		game->player.x = j;
		game->player.y = i;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, PLAYER_XPM, \
								j * TILESIZE, i * TILESIZE);
	}
}

int	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			draw_img(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
