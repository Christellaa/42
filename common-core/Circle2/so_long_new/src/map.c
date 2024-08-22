/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:17:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/22 11:04:10 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	parse_map(t_game *game, char *filename)
{
	int		i;
	int		fd;
	char	*line;
	int		line_len;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Error while opening file\n", -1, game, NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_len = ft_strlen(line);
		if (line_len > 0 && line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		ft_printf("line: %s\n", line);
		ft_strlcpy(game->map.grid[i], line, game->width + 1);
		free(line);
		i++;
	}
	close(fd);
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
