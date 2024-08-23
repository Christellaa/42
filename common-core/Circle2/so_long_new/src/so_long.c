/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:43:39 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/23 16:25:12 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		handle_error("Usage: ./so_long [map.ber]", -1, NULL, NULL);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
		handle_error("Invalid map extension\n", -1, NULL, NULL);
	if (init_game(&game, av[1]) != 0)
		handle_error("Error during game initialization\n", -1, NULL, NULL);
	parse_map(&game, av[1]);
	check_map_validity(&game);
	render_map(&game);
	// move player [interaction]
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, press_key, &game);
	// close window [interaction]
	//mlx_hook(game.win_ptr, DestroyNotify, ButtonPressMask, close_window, &game);
	// win game [interaction]
	//mlx_hook(game.win_ptr, ClientMessage, StructureNotifyMask, win_game, &game);
	// window resized [interaction]
	mlx_loop(game.mlx_ptr);
}
