/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:42:44 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/24 15:54:58 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	get_number_monsters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map.grid[i][j] == MONSTER)
				game->monster_count++;
			j++;
		}
		i++;
	}
	game->monsters = ft_calloc(sizeof(t_monster), game->monster_count);
	if (!game->monsters)
		handle_error("Error while allocating memory to monsters", 0, NULL, \
		NULL);
	i = -1;
	while (++i < game->monster_count)
	{
		game->monsters[i].x = -1;
		game->monsters[i].y = -1;
	}
}

void	check_player_move(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == WALL || game->map.grid[y][x] == OBSTACLE)
		return ;
	if (game->map.grid[y][x] == EXIT)
	{
		if (game->map.validator.c_count == 0)
			win_game(game);
		return ;
	}
	if (game->map.grid[y][x] == MONSTER)
	{
		ft_printf("You were beaten to death by the chicken!\n");
		exit_game(game);
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

void	check_monster_move(t_game *game, int x, int y, int m_count)
{
	if (game->map.grid[y][x] == WALL || game->map.grid[y][x] == OBSTACLE \
		|| game->map.grid[y][x] == MONSTER || game->map.grid[y][x] == EXIT \
		|| game->map.grid[y][x] == COLLECTIBLE)
		return ;
	if (game->map.grid[y][x] == PLAYER)
	{
		ft_printf("You were beaten to death by the chicken!\n");
		exit_game(game);
	}
	game->map.grid[game->monsters[m_count].y][game->monsters[m_count].x] = \
	FLOOR;
	game->monsters[m_count].x = x;
	game->monsters[m_count].y = y;
}

void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;
	int	move_counter;

	new_x = game->player_pos.x + x;
	new_y = game->player_pos.y + y;
	move_counter = game->move_count;
	check_player_move(game, new_x, new_y);
	game->map.grid[game->player_pos.y][game->player_pos.x] = PLAYER;
	if (move_counter != game->move_count)
		ft_printf("Move count: %d\n", game->move_count);
	render_map(game);
}

void	move_monsters(t_game *game, int x, int y, int i)
{
	int	new_x;
	int	new_y;
	int	move;

	new_x = game->monsters[i].x;
	new_y = game->monsters[i].y;
	ft_printf("Monster %d x: %d y: %d\n", i, new_x, new_y);
	move = ft_rand(0, 3);
	if (move == 0)
		new_x += 1;
	else if (move == 1)
		new_x -= 1;
	else if (move == 2)
		new_y += 1;
	else if (move == 3)
		new_y -= 1;
	game->monsters[i].x = new_x + x;
	game->monsters[i].y = new_y + y;
	ft_printf("Monster %d new_x: %d new_y: %d\n", i, new_x, new_y);
	check_monster_move(game, game->monsters[i].x, game->monsters[i].y, i);
	game->map.grid[game->monsters[i].y][game->monsters[i].x] = MONSTER;
	render_map(game);
}
