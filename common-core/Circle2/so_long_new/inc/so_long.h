/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:50:56 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/20 16:57:53 by cde-sous         ###   ########.fr       */
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

# define FLOOR_XPM "textures/floor.xpm"
# define WALL_XPM "textures/wall.xpm"
# define COLLECTIBLE_XPM "textures/collectible.xpm"
# define EXIT_XPM "textures/exit/exit_close.xpm"
# define EXIT_OPEN_XPM "textures/exit/exit_open.xpm"
# define PLAYER_XPM "textures/player/player_bottom.xpm"
# define MONSTER_XPM "textures/monster/monster_left.xpm"
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
	int				**grid;
	t_map_validator	validator;
}	t_map;

typedef struct s_img
{
	void		*img_ptr;
	int			width;
	int			height;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}	t_img;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	t_img		image;
	t_map		map;
	int			height;
	int			width;
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	player;
}	t_game;

// cleanup.c
int		handle_error(char *msg, int fd, t_game *game_free, char **to_free);
void	free_group(char **group);
// inits.c
void	init_map_grid(t_game *game);
void	init_img(t_game *game, char *path);
void	init_imgs(t_game *game);
int		init_game(t_game *game, char *filename);
// map.c
void	parse_map(t_game *game, char *filename);
void	draw_img(t_game *game, t_img *img, int i, int j);
int		render_map(t_game *game);
// checks.c
void	check_params(t_game *game);
void	check_map_edges(t_game *game);
void	check_reachability(t_game *game, int i, int j);
void	check_map_rectangular(t_game *game);
int		check_map_validity(t_game *game);
// interactions.c
void	move_player(t_game *game, int x, int y);
int		press_key(int key, t_game *game);
void	exit_game(t_game *game);
void	close_window(int key, t_game *game);
void	win_game(t_game *game);

#endif
