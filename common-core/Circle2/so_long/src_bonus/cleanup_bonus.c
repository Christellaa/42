/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:30:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/06 15:52:38 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	free_group(t_game *game, char **group)
{
	int	i;

	i = 0;
	if (!group)
		return ;
	while (i < game->height)
	{
		free(group[i]);
		group[i] = NULL;
		i++;
	}
	free(group);
	group = NULL;
}

void	safe_free_img(t_game *game, t_img *img)
{
	if (img->img_ptr)
		mlx_destroy_image(game->mlx_ptr, img->img_ptr);
	img->img_ptr = NULL;
}

void	free_imgs(t_game *game)
{
	if (!game->mlx_ptr)
		return ;
	safe_free_img(game, &game->wall);
	safe_free_img(game, &game->floor);
	safe_free_img(game, &game->collectible);
	safe_free_img(game, &game->exit_close);
	safe_free_img(game, &game->exit_open);
	safe_free_img(game, &game->player_down);
	safe_free_img(game, &game->player_up);
	safe_free_img(game, &game->player_left);
	safe_free_img(game, &game->player_right);
	safe_free_img(game, &game->monster_left);
	safe_free_img(game, &game->monster_right);
	safe_free_img(game, &game->obstacle);
}

int	exit_game(t_game *game, char *msg, char *exit_type)
{
	char	*color;

	if (game)
	{
		free_imgs(game);
		if (game->mlx_ptr)
		{
			if (game->win_ptr)
				mlx_destroy_window(game->mlx_ptr, game->win_ptr);
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
			game->mlx_ptr = NULL;
		}
		free_group(game, game->map.grid);
		if (game->monsters)
		{
			free(game->monsters);
			game->monsters = NULL;
		}
	}
	color = RESET;
	if (ft_strncmp(exit_type, ERROR, 5) == 0)
		color = RED;
	else if (ft_strncmp(exit_type, INFO, 4) == 0)
		color = YELLOW;
	ft_printf("%s%s: %s\n%s", color, exit_type, msg, RESET);
	exit(EXIT_SUCCESS);
}

int	close_game(t_game *game)
{
	exit_game(game, "Game closed", INFO);
	exit(EXIT_SUCCESS);
}
