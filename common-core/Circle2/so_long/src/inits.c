/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:50:48 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/11 13:55:47 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	init_img(t_game *game, t_img *img, char *path)
{
	if (img == &game->main_img)
	{
		img->img_ptr = mlx_new_image(game->mlx_ptr, game->width * TILESIZE, \
				game->height * TILESIZE);
		img->width = game->width * TILESIZE;
		img->height = game->height * TILESIZE;
	}
	else
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
		!init_img(game, &game->main_img, NULL))
		exit_game(game, "Unable to initialize image", ERROR);
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_game(game, "Unable to initialize mlx", ERROR);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILESIZE,
			game->height * TILESIZE, "so_long_bonus");
	if (!game->win_ptr)
		exit_game(game, "Unable to initialize window", ERROR);
	init_imgs(game);
}

void	init_values(t_game *game)
{
	game->player_pos.new_x = -1;
	game->player_pos.new_y = -1;
	game->player_pos.prev_x = -1;
	game->player_pos.prev_y = -1;
	game->exit_pos.x = -1;
	game->exit_pos.y = -1;
	game->player_pos.direction = 4;
	game->map.validator.p_count = 0;
	game->map.validator.e_count = 0;
	game->map.validator.c_count = 0;
	game->map.validator.e_reachable = 0;
	game->map.validator.c_reachable = 0;
	game->move_count = 0;
	game->width = 0;
	game->height = 0;
	game->map.grid = ft_calloc(sizeof(char *), 1);
	if (!game->map.grid)
		exit_game(game, "Unable to allocate memory to grid", ERROR);
}
