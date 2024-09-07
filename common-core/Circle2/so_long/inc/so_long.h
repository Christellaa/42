/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:50:56 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/06 12:30:03 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../X11/X.h"
# include "../X11/keysym.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include "colors.h"
# include "keys.h"
# include "imgs.h"
# include "structs.h"

# define ERROR "Error"
# define WIN "Win"
# define INFO "Info"
# define USAGE "Usage: ./so_long [map.ber]\n"

# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define TILESIZE 60

// cleanup.c
void	free_group(t_game *game, char **group);
void	free_imgs(t_game *game);
void	print_msg(char *msg, char *exit_type);
int		exit_game(t_game *game, char *msg, char *exit_type);
int		close_game(t_game *game);

// inits.c
char	*gnl_newline(int fd);
void	get_map_dimensions(t_game *game, char *filename);
int		init_img(t_game *game, t_img *img, char *path);
int		init_imgs(t_game *game);
int		init_game(t_game *game, char *filename);
// map.c
void	parse_map(t_game *game, char *filename);
t_img	*get_tile(t_game *game, char tile);
int		render_map(t_game *game);
// draw.c
void	draw_base(t_game *game);
void	draw_img(t_game *game, t_img *img, int i, int j);
int		blend_transparency(t_game *game, t_img *img, int x, int y);
// checks.c
void	check_params(t_game *game);
void	check_map_edges(t_game *game);
void	check_map_rectangular(t_game *game);
int		check_map_validity(t_game *game);
// reachability.c
char	**init_checked(t_game *game);
void	flood_fill(t_game *game, int y, int x, char **checked);
void	check_reachability(t_game *game);
// interactions.c
int		check_move(t_game *game, int x, int y);
void	change_player_direction(t_game *game, int direction);
void	move_player(t_game *game, int x, int y);
int		press_key(int key, t_game *game);
int		win_game(t_game *game);

#endif
