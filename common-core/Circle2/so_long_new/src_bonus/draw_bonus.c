/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:50:20 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/26 09:35:09 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	draw_base(t_game *game)
{
	t_img	*floor;
	int		i;
	int		j;

	floor = &game->floor;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			draw_img(game, floor, i, j);
			j++;
		}
		i++;
	}
}

void	draw_img(t_game *game, t_img *img, int i, int j)
{
	int	x;
	int	y;

	x = j * TILESIZE;
	y = i * TILESIZE;
	if (img == &game->player)
	{
		game->player_pos.x = j;
		game->player_pos.y = i;
	}
	else if (img == &game->monster && game->current_monster < \
	game->monster_count)
	{
		ft_printf("draw_img: Monster %d x: %d y: %d\n", game->current_monster, j, i);
		game->monsters[game->current_monster].x = j;
		game->monsters[game->current_monster].y = i;
		ft_printf("2draw_img: Monster %d x: %d y: %d\n", game->current_monster, j, i);
		game->current_monster++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->img_ptr, x, y);
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
