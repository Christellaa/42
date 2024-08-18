/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:20:02 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/15 17:21:00 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	draw_base(t_game *game)
{
	t_img	*floor;
	int		current_row;
	int		current_col;

	floor = &game->floor;
	current_row = 0;
	while (current_row < game->map.rows)
	{
		current_col = 0;
		while (current_col < game->map.cols)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			floor->img_ptr, current_col * TILESIZE, current_row * TILESIZE);
			current_col++;
		}
		current_row++;
	}
	return (0);
}

t_img	*get_tile(t_game *game, char tile)
{
	if (tile == WALL)
		return (&game->wall);
	else if (tile == COLLECTIBLE)
		return (&game->collectible);
	else if (tile == EXIT)
		return (&game->exit);
	else if (tile == PLAYER)
		return (&game->player);
	else if (tile == FLOOR)
		return (&game->floor);
	else
		return (NULL);
}

int	draw_tile(char tile, int row, int col, t_game *game)
{
	t_img	*img;
	int		pos_x;
	int		pos_y;

	pos_x = col * TILESIZE;
	pos_y = row * TILESIZE;
	img = get_tile(game, tile);
	if (!img)
		return (0);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->img_ptr, \
	pos_x, pos_y);
	return (0);
}

int	blend_transparency(t_game *game, t_img *img, int x, int y)
{
	int			i;
	int			j;
	uint32_t	*img_pixel;
	uint32_t	*bg_pixel;

	i = 0;
	if (!img)
		return (0);
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			img_pixel = (uint32_t *)(img->data + (i * img->sizeline) + \
			(j * (img->bpp / 8)));
			bg_pixel = (uint32_t *)(game->floor.data + \
			(i * game->floor.sizeline) + (j * (img->bpp / 8)));
			if ((*img_pixel & 0xFF000000) != 0)
				*img_pixel = *bg_pixel;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->img_ptr, x, y);
	return (0);
}
