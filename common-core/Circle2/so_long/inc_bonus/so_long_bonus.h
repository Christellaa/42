/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:50:56 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/07 15:30:53 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../X11/X.h"
# include "../X11/keysym.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include "colors_bonus.h"
# include "keys_bonus.h"
# include "imgs_bonus.h"
# include "structs_bonus.h"

# define ERROR "Error\n"
# define INFO "Info\n"
# define USAGE "Usage: ./so_long [map.ber]"

# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define MONSTER 'M'
# define OBSTACLE 'O'

# define TILESIZE 60

// cleanup_bonus.c
void	free_group(t_game *game, char **group);
void	safe_free_img(t_game *game, t_img *img);
void	free_imgs(t_game *game);
int		exit_game(t_game *game, char *msg, char *exit_type);
int		close_game(t_game *game);
// inits_bonus.c
void	init_and_locate_monsters(t_game *game, int i, int j);
int		init_img(t_game *game, t_img *img, char *path);
void	init_imgs(t_game *game);
void	init_game(t_game *game);
void	init_values(t_game *game);
// map_bonus.c
char	*gnl_newline(int fd);
void	parse_map(t_game *game, char *filename);
t_img	*get_tile(t_game *game, char tile);
t_img	*get_tile2(t_game *game, char tile);
void	render_map(t_game *game);
// draw_bonus.c
void	display_moves_on_screen(t_game *game);
void	put_pixel_to_img(t_game *game, t_img *img, int x, int y);
void	draw_base(t_game *game);
void	draw_img(t_game *game, t_img *img, int i, int j);
// so_long_utils_bonus.c
int		open_fd(t_game *game, char *filename);
void	check_map_line(t_game *game, int i);
void	print_msg(char *msg, char *exit_type);
// checks_bonus.c
void	count_and_locate_chars(t_game *game, int i, int j);
void	check_params(t_game *game, int i);
void	check_map_edges(t_game *game, int i);
void	check_map_rectangular(t_game *game);
int		check_map_validity(t_game *game);
// reachability_bonus.c
void	flood_fill(t_game *game, int y, int x, char **checked);
char	**init_checked(t_game *game);
void	check_reachability(t_game *game);
// interactions_bonus.c
void	change_player_direction(t_game *game, int direction);
void	change_monsters_direction(t_game *game, int direction);
void	get_key(int key, t_game *game);
int		press_key(int key, t_game *game);
int		win_game(t_game *game);
// moves_bonus.c
int		check_player_move(t_game *game, int x, int y);
int		check_monster_move(t_game *game, int x, int y, int i);
void	move_player(t_game *game, int x, int y);
void	move_monsters(t_game *game, int new_x, int new_y, int i);

#endif
