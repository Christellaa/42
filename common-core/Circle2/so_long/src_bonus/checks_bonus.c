/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:33:00 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/02 21:11:09 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	check_params(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01CEPMO", line[i]))
			exit_game(game, "Invalid character in map", ERROR);
		if (line[i] == PLAYER)
		{
			if (game->map.validator.p_count > 0)
				exit_game(game, "Multiple players in map", ERROR);
			game->map.validator.p_count++;
		}
		if (line[i] == EXIT)
		{
			if (game->map.validator.e_count > 0)
				exit_game(game, "Multiple exits in map", ERROR);
			game->map.validator.e_count++;
		}
		if (line[i] == COLLECTIBLE)
			game->map.validator.c_count++;
		i++;
	}
}

void	check_map_edges(t_game *game, char *line, int idx)
{
	int	i;

	if (line[0] != WALL)
		exit_game(game, "Map is not closed by walls at first column", ERROR);
	if (line[ft_strlen(line) - 1] != WALL)
		exit_game(game, "Map is not closed by walls at last column", ERROR);
	if (idx == 0 || idx == game->height - 1)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] != WALL)
			{
				if (idx == 0)
					exit_game(game, "Map is not closed by walls at first line", ERROR);
				else
					exit_game(game, "Map is not closed by walls at last line", ERROR);
			}
			i++;
		}
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
		{
			if (game->map.grid[i][j] == '\0')
				exit_game(game, "Map is not rectangular", ERROR);
			j++;
		}
		if (j != game->width)
			exit_game(game, "Map is not rectangular", ERROR);
		i++;
	}
	if (i != game->height)
		exit_game(game, "Map is not rectangular", ERROR);
}

int	check_map_validity(t_game *game)
{
	check_map_rectangular(game);
	if (game->map.validator.p_count != 1)
		exit_game(game, "Player count is not valid", ERROR);
	if (game->map.validator.e_count != 1)
		exit_game(game, "Exit count is not valid", ERROR);
	if (game->map.validator.c_count < 1)
		exit_game(game, "Collectible count is not valid", ERROR);
	check_reachability(game);
	if (game->map.validator.e_reachable == 0)
		exit_game(game, "Exit is not reachable", ERROR);
	if (game->map.validator.c_reachable != game->map.validator.c_count)
		exit_game(game, "Collectibles are not reachable", ERROR);
	return (0);
}

int	check_chars(t_game *game, char *line, int idx)
{
	check_params(game, line);
	check_map_edges(game, line, idx);
	return (0);
}
