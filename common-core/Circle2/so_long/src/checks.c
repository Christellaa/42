/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:33:00 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/11 13:46:10 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	count_and_locate_chars(t_game *game, int i, int j)
{
	if (game->map.grid[i][j] == PLAYER)
	{
		game->map.validator.p_count++;
		if (game->map.validator.p_count != 1)
			exit_game(game, "Multiple players in map", ERROR);
		game->player_pos.new_x = j;
		game->player_pos.new_y = i;
	}
	if (game->map.grid[i][j] == EXIT)
	{
		game->map.validator.e_count++;
		if (game->map.validator.e_count != 1)
			exit_game(game, "Multiple exits in map", ERROR);
		game->exit_pos.x = j;
		game->exit_pos.y = i;
	}
	if (game->map.grid[i][j] == COLLECTIBLE)
		game->map.validator.c_count++;
}

void	check_params(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->map.grid[i][j])
	{
		if (!ft_strchr("01CEP", game->map.grid[i][j]))
			exit_game(game, "Invalid character in map", ERROR);
		count_and_locate_chars(game, i, j);
		j++;
	}
}

void	check_map_edges(t_game *game, int i)
{
	int	j;

	j = 0;
	while (i == 0 && game->map.grid[i][j])
	{
		if (game->map.grid[i][j] != WALL)
			exit_game(game, "Map is not closed by walls at first line", ERROR);
		j++;
	}
	if (i > 0 && (int)ft_strlen(game->map.grid[i]) != game->width)
		exit_game(game, "Map is not rectangular", ERROR);
	if (game->map.grid[i][0] != WALL \
	|| game->map.grid[i][game->width - 1] != WALL)
		exit_game(game, \
		"Map is not closed by walls at first and/or last column", ERROR);
}

void	check_last_line(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map.grid[game->height - 1][i] != WALL)
			exit_game(game, \
			"Map is not closed by walls at last line, or blank line somewhere"\
			, ERROR);
		i++;
	}
}

void	check_map_rectangular(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
			j++;
		if (j != game->width)
			exit_game(game, "Map is not rectangular", ERROR);
		i++;
	}
}
