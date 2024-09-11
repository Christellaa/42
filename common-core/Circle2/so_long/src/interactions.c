/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:21:28 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/11 13:52:46 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_move(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == WALL)
	{
		game->player_pos.prev_x = game->player_pos.new_x;
		game->player_pos.prev_y = game->player_pos.new_y;
		return (0);
	}
	if (game->map.grid[y][x] == EXIT)
	{
		if (game->map.validator.c_count == 0)
			win_game(game);
		return (0);
	}
	game->map.grid[game->player_pos.new_y][game->player_pos.new_x] = FLOOR;
	if (game->map.grid[y][x] == COLLECTIBLE)
	{
		game->map.grid[y][x] = FLOOR;
		game->map.validator.c_count--;
	}
	return (1);
}

void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;
	int	move_counter;

	new_x = game->player_pos.new_x + x;
	new_y = game->player_pos.new_y + y;
	move_counter = game->move_count;
	if (check_move(game, new_x, new_y))
	{
		game->move_count++;
		game->player_pos.prev_x = game->player_pos.new_x;
		game->player_pos.prev_y = game->player_pos.new_y;
		game->player_pos.new_x = new_x;
		game->player_pos.new_y = new_y;
		game->map.grid[game->player_pos.new_y][game->player_pos.new_x] = PLAYER;
	}
	if (move_counter != game->move_count)
		ft_printf("Move count: %d\n", game->move_count);
	redraw_changes(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->main_img.img_ptr, 0, 0);
}

int	press_key(int key, t_game *game)
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
	return (0);
}

int	win_game(t_game *game)
{
	ft_printf("%sYou won the game in %d moves!\n%s", GREEN, game->move_count, \
	RESET);
	close_game(game);
	return (0);
}
