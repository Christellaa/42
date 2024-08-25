/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:30:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/25 19:44:58 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	free_imgs(t_game *game)
{
	if (!game->mlx_ptr)
		return ;
	mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->collectible.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_close.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_open.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_down.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_up.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_left.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_right.img_ptr);

	game->wall.img_ptr = NULL;
	game->floor.img_ptr = NULL;
	game->collectible.img_ptr = NULL;
	game->exit_close.img_ptr = NULL;
	game->exit_open.img_ptr = NULL;
	game->player_down.img_ptr = NULL;
	game->player_up.img_ptr = NULL;
	game->player_left.img_ptr = NULL;
	game->player_right.img_ptr = NULL;
}

void	print_msg(char *msg, char *exit_type)
{
	char	*color;

	if (ft_strncmp(exit_type, "ERROR", 5) == 0)
		color = RED;
	else if (ft_strncmp(exit_type, "WIN", 3) == 0)
		color = GREEN;
	else if (ft_strncmp(exit_type, "INFO", 4) == 0)
		color = YELLOW;
	else
		color = WHITE;
	ft_printf("%s%s: %s\n%s", color, exit_type, msg, RESET);
}

int	exit_game(t_game *game, char *msg, char *exit_type)
{
	if (game)
	{
		free_imgs(game);
		if (game->mlx_ptr)
		{
			if (game->win_ptr)
				mlx_destroy_window(game->mlx_ptr, game->win_ptr);
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
		free_group(game, game->map.grid);
	}
	print_msg(msg, exit_type);
	exit(EXIT_SUCCESS);
}

int	close_game(t_game *game)
{
	exit_game(game, "Game closed", "INFO");
	exit(EXIT_SUCCESS);
}
