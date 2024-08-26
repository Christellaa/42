/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:42:44 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/26 15:38:01 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	check_player_move(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == WALL || game->map.grid[y][x] == OBSTACLE)
		return (0);
	if (game->map.grid[y][x] == EXIT)
	{
		if (game->map.validator.c_count == 0)
			win_game(game);
		return (0);
	}
	if (game->map.grid[y][x] == MONSTER)
		exit_game(game, "You were beaten to death by the chicken!", INFO);
	game->map.grid[game->player_pos.y][game->player_pos.x] = FLOOR;
	if (game->map.grid[y][x] == COLLECTIBLE)
	{
		game->map.grid[y][x] = FLOOR;
		game->map.validator.c_count--;
		if (game->map.validator.c_count == 0)
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->exit_open.img_ptr, game->exit_pos.x * TILESIZE,
				game->exit_pos.y * TILESIZE);
	}
	return (1);
}

int	check_monster_move(t_game *game, int x, int y, int i)
{
	if (game->map.grid[y][x] == WALL || game->map.grid[y][x] == OBSTACLE \
		|| game->map.grid[y][x] == MONSTER || game->map.grid[y][x] == EXIT \
		|| game->map.grid[y][x] == COLLECTIBLE)
		return (0);
	if (game->map.grid[y][x] == PLAYER)
		exit_game(game, "You were beaten to death by the chicken!", INFO);
	game->map.grid[game->monsters[i].y][game->monsters[i].x] = FLOOR;
	return (1);
}

void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;
	int	move_counter;

	new_x = game->player_pos.x + x;
	new_y = game->player_pos.y + y;
	move_counter = game->move_count;
	if (check_player_move(game, new_x, new_y))
	{
		game->player_pos.x = new_x;
		game->player_pos.y = new_y;
		game->map.grid[game->player_pos.y][game->player_pos.x] = PLAYER;
		game->player_pos.is_moving = 1;
	}
	if (move_counter != game->move_count)
		ft_printf("Move count: %d\n", game->move_count);
}

void	move_monsters(t_game *game, int new_x, int new_y, int i)
{
	int	move;

	move = ft_rand(0, 200);
	if (move < 50)
	{
		change_monsters_direction(game, 1);
		new_x += 1;
	}
	else if (move < 100)
	{
		change_monsters_direction(game, 2);
		new_x -= 1;
	}
	else if (move < 150)
		new_y += 1;
	else
		new_y -= 1;
	if (check_monster_move(game, new_x, new_y, i))
	{
		game->monsters[i].x = new_x;
		game->monsters[i].y = new_y;
		game->map.grid[game->monsters[i].y][game->monsters[i].x] = MONSTER;
	}
}
