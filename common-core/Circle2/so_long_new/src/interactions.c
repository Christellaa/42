/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:21:28 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/22 12:23:42 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + x;
	new_y = game->player.y + y;
	if (game->map.grid[new_y][new_x] == WALL)
		return ;
	else if (game->map.grid[new_y][new_x] == COLLECTIBLE)
	{
		game->map.grid[new_y][new_x] = FLOOR;
		// is it useful if the other down there is used?
		game->map.validator.c_count--;
	}
	else if (game->map.grid[new_y][new_x] == EXIT)
	{
		//if (game->map.validator.c_count == 0)
			//todo
		//else
		return ;
	}
	game->map.grid[game->player.y][game->player.x] = FLOOR;
	// is it useful is the other up there is used?
	game->player.x = new_x;
	game->player.y = new_y;
	game->map.grid[game->player.y][game->player.x] = PLAYER;
	render_map(game);
}

int	press_key(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
		move_player(game, 0, -1);
	if (key == KEY_A || key == KEY_LEFT)
		move_player(game, -1, 0);
	if (key == KEY_S || key == KEY_DOWN)
		move_player(game, 0, 1);
	if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}

void	exit_game(t_game *game)
{
	//free(&game->map);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}

void	close_window(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		ft_printf("You closed the window key!\n");
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit_game(game);
	}
	// mouse click on red cross
	if (key == 17)
	{
		ft_printf("You closed the window cross!\n");
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit_game(game);
	}
}
/* 
void	win_game(t_game *game)
{
	//todo
}
 */
