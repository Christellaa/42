/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachability.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:52:53 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/26 15:04:48 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	flood_fill(t_game *game, int i, int j, char **checked)
{
	if (i < 0 || i >= game->height || j < 0 || j >= game->width)
		return ;
	if (game->map.grid[i][j] == WALL || checked[i][j])
		return ;
	if (game->map.grid[i][j] == EXIT)
		game->map.validator.e_reachable = 1;
	if (game->map.grid[i][j] == COLLECTIBLE)
		game->map.validator.c_reachable++;
	checked[i][j] = 1;
	flood_fill(game, i - 1, j, checked);
	flood_fill(game, i + 1, j, checked);
	flood_fill(game, i, j - 1, checked);
	flood_fill(game, i, j + 1, checked);
}

char	**init_checked(t_game *game)
{
	char	**checked;
	int		i;

	checked = ft_calloc(sizeof(char *), game->height);
	if (!checked)
		exit_game(game, "Unable to allocate memory to checked", ERROR);
	i = 0;
	while (i < game->height)
	{
		checked[i] = ft_calloc(sizeof(char), game->width);
		if (!checked[i])
			exit_game(game, "Unable to allocate memory to checked", ERROR);
		i++;
	}
	return (checked);
}

void	check_reachability(t_game *game)
{
	char	**checked;
	int		i;
	int		j;

	checked = init_checked(game);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map.grid[i][j] == PLAYER)
				flood_fill(game, i, j, checked);
			j++;
		}
		i++;
	}
	free_group(game, checked);
}
