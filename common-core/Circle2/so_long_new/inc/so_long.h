/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:50:56 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/20 10:23:21 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
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

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// with keysim of X11
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

typedef struct s_layer
{
	char	**tiles;
}	t_layer;

typedef struct s_map
{
	t_layer			*layers[3];
	int				rows;
	int				cols;
	t_map_validator	validator;
}	t_map;

typedef struct s_img
{
	void		*img_ptr;
	int			width;
	int			height;
	char		*data;
	int			bpp; //bits per pixel
	int			sizeline; // size of each line in bytes
	int			endian;
}	t_img;

typedef struct s_game
{
	t_img	floor;
	t_img	wall;
	t_img	collectible;
	t_img	exit;
	t_img	player;
	t_img	monster;
	t_img	obstacle;
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	**map;
	int		player_x;
	int		player_y;
}	t_game;

// cleanup.c
int		handle_error(char *msg, int fd, char **to_free, int **to_free2);
void	free_group_char(char **group);
void	free_group_int(int **group);
int		open_or_reset_fd(int fd, char *filename);

#endif
