/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:43:39 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/07 15:08:59 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (ac != 2)
		exit_game(&game, USAGE, ERROR);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
		exit_game(&game, "Invalid map extension", ERROR);
	init_values(&game);
	parse_map(&game, av[1]);
	if (game.width <= 0 || game.height <= 0)
		exit_game(&game, "Invalid map dimensions", ERROR);
	check_map_validity(&game);
	init_game(&game);
	render_map(&game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, press_key, &game);
	mlx_hook(game.win_ptr, DestroyNotify, ButtonPressMask, close_game, &game);
	mlx_hook(game.win_ptr, ClientMessage, StructureNotifyMask, win_game, &game);
	mlx_loop(game.mlx_ptr);
	return (-1);
}
