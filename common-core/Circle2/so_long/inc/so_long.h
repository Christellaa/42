/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:50:56 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/11 13:45:25 by cde-sous         ###   ########.fr       */
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

# define ERROR "Error\n"
# define INFO "Info\n"
# define USAGE "Usage: ./so_long [map.ber]"

# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define TILESIZE 60

// cleanup.c
void	free_group(t_game *game, char **group);
void	safe_free_img(t_game *game, t_img *img);
void	free_imgs(t_game *game);
int		exit_game(t_game *game, char *msg, char *exit_type);
int		close_game(t_game *game);
// inits.c
int		init_img(t_game *game, t_img *img, char *path);
void	init_imgs(t_game *game);
void	init_game(t_game *game);
void	init_values(t_game *game);
// map.c
void	parse_map(t_game *game, char *filename);
t_img	*get_tile(t_game *game, char tile);
void	render_map(t_game *game);
// draw.c
void	put_pixel_to_img(t_game *game, t_img *img, int x, int y);
void	draw_base(t_game *game);
void	draw_img(t_game *game, t_img *img, int i, int j);
void	redraw_changes(t_game *game);
// utils.c
char	*gnl_newline(int fd);
int		open_fd(t_game *game, char *filename);
void	print_msg(char *msg, char *exit_type);
void	check_map_line(t_game *game, int i);
int		check_map_validity(t_game *game);
// checks.c
void	count_and_locate_chars(t_game *game, int i, int j);
void	check_params(t_game *game, int i);
void	check_map_edges(t_game *game, int i);
void	check_last_line(t_game *game);
void	check_map_rectangular(t_game *game);
// reachability.c
void	flood_fill(t_game *game, int y, int x, char **checked);
char	**init_checked(t_game *game);
void	check_reachability(t_game *game);
// interactions.c
int		check_move(t_game *game, int x, int y);
void	move_player(t_game *game, int x, int y);
int		press_key(int key, t_game *game);
int		win_game(t_game *game);

#endif
