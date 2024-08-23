/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:50:56 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/23 20:00:44 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../X11/X.h"
# include "../X11/keysym.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include <fcntl.h>

# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define MONSTER 'M'
# define OBSTACLE 'O'

// with keysim of X11
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_ESC 65307

# define WALL_XPM "textures/wall.xpm"
# define FLOOR_XPM "textures/floor.xpm"
# define COLLECTIBLE_XPM "textures/collectible.xpm"
# define EXIT_XPM "textures/exit/exit_close.xpm"
# define EXIT_OPEN_XPM "textures/exit/exit_open.xpm"
# define PLAYER_UP_XPM "textures/player/player_up.xpm"
# define PLAYER_DOWN_XPM "textures/player/player_down.xpm"
# define PLAYER_LEFT_XPM "textures/player/player_left.xpm"
# define PLAYER_RIGHT_XPM "textures/player/player_right.xpm"
# define MONSTER_LEFT_XPM "textures/monster/monster_left.xpm"
# define MONSTER_RIGHT_XPM "textures/monster/monster_right.xpm"
# define OBSTACLE_XPM "textures/obstacle.xpm"

# define TILESIZE 60

typedef struct s_map_validator
{
	int	p_count;
	int	e_count;
	int	c_count;
	int	e_reachable;
	int	c_reachable;
}	t_map_validator;

typedef struct s_map
{
	char			**grid;
	t_map_validator	validator;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		sizeline;
	int		endian;
}	t_img;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	t_img		wall;
	t_img		floor;
	t_img		collectible;
	t_img		exit;
	t_img		player;
	t_map		map;
	int			height;
	int			width;
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	player_pos;
	int			move_count;
}	t_game;

// cleanup.c
int		handle_error(char *msg, int fd, t_game *game_free, char **to_free);
void	free_group(char **group);
// inits.c
char	*gnl_newline(int fd);
void	get_map_dimensions(t_game *game, char *filename);
void	init_img(t_game *game, t_img *img, char *path);
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
void	move_player(t_game *game, int x, int y);
int		press_key(int key, t_game *game);
void	exit_game(t_game *game);
void	close_window(int key, t_game *game);
void	win_game(t_game *game);

#endif
