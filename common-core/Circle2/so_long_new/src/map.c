/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:17:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/20 17:00:51 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	parse_map(t_game *game, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Error during map reading\n", -1, game, NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line == -1)
			handle_error("Error during map reading\n", -1, game, NULL);
		if (line == 0)
			break ;
		ft_strlcpy(game->map.grid[i], line, game->width + 1);
		free(line);
		i++;
	}
	game->height = i;
	game->width = ft_strlen(line);
	close(fd);
}

void	draw_img(t_game *game, t_img *img, int i, int j)
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
			draw_img(game, &game->image, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
