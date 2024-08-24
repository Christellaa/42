/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:21:28 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/24 16:13:23 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	get_key(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
	{
		init_img(game, &game->player, PLAYER_UP_XPM);
		game->player_pos.y -= 1;
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		init_img(game, &game->player, PLAYER_LEFT_XPM);
		move_player(game, -1, 0);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		init_img(game, &game->player, PLAYER_DOWN_XPM);
		game->player_pos.y += 1;
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		init_img(game, &game->player, PLAYER_RIGHT_XPM);
		move_player(game, 1, 0);
	}
}

int	press_key(int key, t_game *game)
{
	get_key(key, game);
	game->current_monster = 0;
	while (game->current_monster < game->monster_count)
	{
		ft_printf("monster count: %d, current monster: %d\n", game->monster_count, game->current_monster);
		move_monsters(game, game->monsters[game->current_monster].x, \
		game->monsters[game->current_monster].y, game->current_monster);
		game->current_monster++;
	}
	ft_printf("current monster: %d\n", game->current_monster);
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

int	win_game(t_game *game)
{
	ft_printf("You won the game in %d moves!\n", game->move_count);
	exit_game(game);
	return (0);
}
