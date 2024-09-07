/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:50:20 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/07 15:13:30 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	display_moves_on_screen(t_game *game)
{
	char	*move_count;

	move_count = ft_itoa(game->move_count);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 20, 255, "Moves:");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 50, 21, 255, move_count);
	if (move_count)
		free(move_count);
}

void	put_pixel_to_img(t_game *game, t_img *img, int x, int y)
{
	char	*dest;
	char	*color;
	int		tile_x;
	int		tile_y;

	tile_y = 0;
	while (tile_y < TILESIZE && (y + tile_y) < game->main_img.height)
	{
		tile_x = 0;
		while (tile_x < TILESIZE && (x + tile_x) < game->main_img.width)
		{
			if (tile_x < img->width && tile_y < img->height)
			{
				color = img->data + (tile_y * img->sizeline + \
				tile_x * (img->bpp / 8));
				dest = game->main_img.data + ((y + tile_y) * \
				game->main_img.sizeline + (x + tile_x) * \
				(game->main_img.bpp / 8));
				if (*(uint32_t *)color != 0xFF000000)
					*(uint32_t *)dest = *(uint32_t *)color;
			}
			tile_x++;
		}
		tile_y++;
	}
}

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
	put_pixel_to_img(game, img, x, y);
	if (img == &game->player_down || img == &game->player_up || \
	img == &game->player_left || img == &game->player_right)
	{
		game->player_pos.x = j;
		game->player_pos.y = i;
	}
	if (img == &game->exit_close)
	{
		game->exit_pos.x = j;
		game->exit_pos.y = i;
	}
	else if ((img == &game->monster_left || img == &game->monster_right) \
	&& game->current_monster < game->monster_count)
	{
		game->monsters[game->current_monster].x = j;
		game->monsters[game->current_monster].y = i;
		game->current_monster++;
	}
}
