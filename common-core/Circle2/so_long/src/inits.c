/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:12:17 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/15 16:43:00 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_layers(t_layer *layers[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		layers[i] = malloc(sizeof(t_layer));
		if (!layers[i])
			handle_error("malloc layer structure", -1, NULL, NULL);
		layers[i]->tiles = NULL;
		i++;
	}
}

void	init_map(t_map *map)
{
	init_layers(map->layers);
	map->validator.c_count = 0;
	map->validator.e_count = 0;
	map->validator.p_count = 0;
	map->validator.map_valid = 1;
	map->rows = 0;
	map->cols = 0;
}

void	init_img(t_img *img, char *path, t_game *game)
{
	img->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &img->width, \
	&img->height);
	if (!img->img_ptr)
		handle_error("Load image", -1, NULL, NULL);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->sizeline, \
	&img->endian);
	if (!img->data)
		handle_error("Get image data", -1, NULL, NULL);
}

int	init_imgs(t_game *game)
{
	init_img(&game->floor, FLOOR_XPM, game);
	init_img(&game->wall, WALL_XPM, game);
	init_img(&game->collectible, COLLECTIBLE_XPM, game);
	init_img(&game->exit, EXIT_XPM, game);
	init_img(&game->player, PLAYER_XPM, game);
	if (!game->floor.img_ptr || !game->wall.img_ptr || \
	!game->collectible.img_ptr || !game->exit.img_ptr || !game->player.img_ptr)
		handle_error("initialize images", -1, NULL, NULL);
	return (0);
}

int	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		handle_error("initialize mlx", -1, NULL, NULL);
	game->height = game->map.cols * TILESIZE;
	game->width = game->map.rows * TILESIZE;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->height, game->width, \
	"Game");
	init_imgs(game);
	return (0);
}
