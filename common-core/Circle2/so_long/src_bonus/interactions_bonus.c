/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:21:28 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/07 18:48:49 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	get_key(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
	{
		game->player_pos.direction = 2;
		move_player(game, 0, -1);
	}
	if (key == KEY_A || key == KEY_LEFT)
	{
		game->player_pos.direction = 1;
		move_player(game, -1, 0);
	}
	if (key == KEY_S || key == KEY_DOWN)
	{
		game->player_pos.direction = 4;
		move_player(game, 0, 1);
	}
	if (key == KEY_D || key == KEY_RIGHT)
	{
		game->player_pos.direction = 3;
		move_player(game, 1, 0);
	}
	if (key == KEY_ESC)
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
