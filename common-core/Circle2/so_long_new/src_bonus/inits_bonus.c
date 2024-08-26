/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:50:48 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/26 15:30:15 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	get_map_dimensions(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_game(game, "Unable to open map file", ERROR);
	game->width = 0;
	game->height = 0;
	line = gnl_newline(fd);
	while (line)
	{
		if (game->width <= 0)
			game->width = ft_strlen(line);
		game->height++;
		free(line);
		line = gnl_newline(fd);
	}
	free(line);
	close(fd);
	if (game->width <= 0 || game->height <= 0)
		exit_game(game, "Invalid map dimensions", ERROR);
}

void	get_number_monsters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map.grid[i][j] == MONSTER)
				game->monster_count++;
			j++;
		}
		i++;
	}
	game->monsters = ft_calloc(sizeof(t_monster), game->monster_count);
	if (!game->monsters)
		exit_game(game, "Unable to allocate memory to monsters", ERROR);
	i = -1;
	while (++i < game->monster_count)
	{
		game->monsters[i].x = -1;
		game->monsters[i].y = -1;
		game->monsters[i].direction = 1;
	}
}

int	init_img(t_game *game, t_img *img, char *path)
{
	img->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&img->width, &img->height);
	if (!img->img_ptr)
		exit_game(game, "Unable to initialize image", ERROR);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	if (!img->data)
		exit_game(game, "Unable to initialize image", ERROR);
	return (1);
}

void	init_imgs(t_game *game)
{
	if (!init_img(game, &game->wall, WALL_XPM) || \
		!init_img(game, &game->floor, FLOOR_XPM) || \
		!init_img(game, &game->collectible, COLLECTIBLE_XPM) || \
		!init_img(game, &game->exit_close, EXIT_CLOSE_XPM) || \
		!init_img(game, &game->exit_open, EXIT_OPEN_XPM) || \
		!init_img(game, &game->player_down, PLAYER_DOWN_XPM) || \
		!init_img(game, &game->player_up, PLAYER_UP_XPM) || \
		!init_img(game, &game->player_left, PLAYER_LEFT_XPM) || \
		!init_img(game, &game->player_right, PLAYER_RIGHT_XPM) || \
		!init_img(game, &game->monster_left, MONSTER_LEFT_XPM) || \
		!init_img(game, &game->monster_right, MONSTER_RIGHT_XPM) || \
		!init_img(game, &game->obstacle, OBSTACLE_XPM))
		exit_game(game, "Unable to initialize image", ERROR);
}

int	init_game(t_game *game, char *filename)
{
	get_map_dimensions(game, filename);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_game(game, "Unable to initialize mlx", ERROR);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILESIZE,
			game->height * TILESIZE, "so_long_bonus");
	if (!game->win_ptr)
		exit_game(game, "Unable to initialize window", ERROR);
	init_imgs(game);
	game->player_pos.x = -1;
	game->player_pos.y = -1;
	game->exit_pos.x = -1;
	game->exit_pos.y = -1;
	game->player_pos.direction = 4;
	game->player_pos.is_moving = 0;
	game->monster_count = 0;
	game->current_monster = 0;
	game->map.validator.p_count = 0;
	game->map.validator.e_count = 0;
	game->map.validator.c_count = 0;
	game->map.validator.e_reachable = 0;
	game->map.validator.c_reachable = 0;
	game->move_count = 0;
	return (0);
}
