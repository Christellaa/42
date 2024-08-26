/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:21:28 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/26 15:52:52 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	change_player_direction(t_game *game, int direction)
{
	game->player_pos.direction = direction;
	if (game->player_pos.direction == 1)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_left.img_ptr, game->player_pos.x * TILESIZE,
			game->player_pos.y * TILESIZE);
	}
	if (game->player_pos.direction == 2)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_up.img_ptr, game->player_pos.x * TILESIZE,
			game->player_pos.y * TILESIZE);
	}
	if (game->player_pos.direction == 3)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_right.img_ptr, game->player_pos.x * TILESIZE,
			game->player_pos.y * TILESIZE);
	}
	if (game->player_pos.direction == 4)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player_down.img_ptr, game->player_pos.x * TILESIZE,
			game->player_pos.y * TILESIZE);
	}
}

void	change_monsters_direction(t_game *game, int direction)
{
	game->monsters[game->current_monster].direction = direction;
	if (game->monsters[game->current_monster].direction == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->monster_left.img_ptr, \
			game->monsters[game->current_monster].x * TILESIZE,
			game->monsters[game->current_monster].y * TILESIZE);
	else if (game->monsters[game->current_monster].direction == 2)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->monster_right.img_ptr, \
			game->monsters[game->current_monster].x * TILESIZE,
			game->monsters[game->current_monster].y * TILESIZE);
}

void	get_key(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
	{
		change_player_direction(game, 2);
		move_player(game, 0, -1);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		change_player_direction(game, 1);
		move_player(game, -1, 0);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		change_player_direction(game, 4);
		move_player(game, 0, 1);
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		change_player_direction(game, 3);
		move_player(game, 1, 0);
	}
	else if (key == KEY_ESC)
		close_game(game);
}

int	press_key(int key, t_game *game)
{
	int	new_x;
	int	new_y;

	get_key(key, game);
	game->current_monster = 0;
	if (game->player_pos.is_moving)
	{
		game->move_count++;
		ft_printf("is_moving: %d\n", game->player_pos.is_moving);
		while (game->current_monster < game->monster_count)
		{
			new_x = game->monsters[game->current_monster].x;
			new_y = game->monsters[game->current_monster].y;
			move_monsters(game, new_x, new_y, game->current_monster);
			game->current_monster++;
		}
		game->player_pos.is_moving = 0;
	}
	render_map(game);
	return (0);
}

int	win_game(t_game *game)
{
	ft_printf("%sYou won the game in %d moves!\n%s", GREEN, game->move_count, \
	RESET);
	close_game(game);
	return (0);
}
