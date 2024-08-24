/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:21:28 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/24 10:45:39 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_move(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == WALL)
		return ;
	if (game->map.grid[y][x] == EXIT)
	{
		if (game->map.validator.c_count == 0)
			win_game(game);
		return ;
	}
	game->map.grid[game->player_pos.y][game->player_pos.x] = FLOOR;
	game->player_pos.x = x;
	game->player_pos.y = y;
	game->move_count++;
	if (game->map.grid[y][x] == COLLECTIBLE)
	{
		game->map.grid[y][x] = FLOOR;
		game->map.validator.c_count--;
		if (game->map.validator.c_count == 0)
			init_img(game, &game->exit, EXIT_OPEN_XPM);
	}
}

void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;
	int	move_counter;

	new_x = game->player_pos.x + x;
	new_y = game->player_pos.y + y;
	move_counter = game->move_count;
	check_move(game, new_x, new_y);
	game->map.grid[game->player_pos.y][game->player_pos.x] = PLAYER;
	if (move_counter != game->move_count)
		ft_printf("Move count: %d\n", game->move_count);
	render_map(game);
}

int	press_key(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
	{
		init_img(game, &game->player, PLAYER_UP_XPM);
		move_player(game, 0, -1);
	}
	if (key == KEY_A || key == KEY_LEFT)
	{
		init_img(game, &game->player, PLAYER_LEFT_XPM);
		move_player(game, -1, 0);
	}
	if (key == KEY_S || key == KEY_DOWN)
	{
		init_img(game, &game->player, PLAYER_DOWN_XPM);
		move_player(game, 0, 1);
	}
	if (key == KEY_D || key == KEY_RIGHT)
	{
		init_img(game, &game->player, PLAYER_RIGHT_XPM);
		move_player(game, 1, 0);
	}
	if (key == KEY_ESC)
		exit_game(game);
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
