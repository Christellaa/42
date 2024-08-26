/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:58:50 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/26 15:29:38 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

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

typedef struct s_monster
{
	int	x;
	int	y;
	int	direction;
}	t_monster;

typedef struct s_player
{
	int	x;
	int	y;
	int	direction;
	int	is_moving;
}	t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}	t_exit;

typedef struct s_game
{
	t_img		wall;
	t_img		floor;
	t_img		collectible;
	t_img		exit_close;
	t_img		exit_open;
	t_img		player_down;
	t_img		player_up;
	t_img		player_left;
	t_img		player_right;
	t_img		monster_left;
	t_img		monster_right;
	t_img		obstacle;
	t_map		map;
	int			height;
	int			width;
	void		*mlx_ptr;
	void		*win_ptr;
	int			move_count;
	t_player	player_pos;
	t_exit		exit_pos;
	t_monster	*monsters;
	int			monster_count;
	int			current_monster;
}	t_game;

#endif