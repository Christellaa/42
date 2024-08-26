/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:17:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/26 15:40:25 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

char	*gnl_newline(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

void	parse_map(t_game *game, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_game(game, "Unable to open map file", ERROR);
	game->map.grid = ft_calloc(sizeof(char *), (game->height + 1));
	if (!game->map.grid)
	{
		close(fd);
		exit_game(game, "Unable to allocate memory to grid", ERROR);
	}
	i = 0;
	line = gnl_newline(fd);
	while (line)
	{
		game->map.grid[i] = ft_strdup(line);
		free(line);
		line = gnl_newline(fd);
		i++;
	}
	free(line);
	close(fd);
	game->map.grid[i] = NULL;
}


t_img	*get_tile(t_game *game, char tile)
{
	if (tile == WALL)
		return (&game->wall);
	else if (tile == FLOOR)
		return (&game->floor);
	else if (tile == COLLECTIBLE)
		return (&game->collectible);
	else if (tile == EXIT)
	{
		if (game->map.validator.c_count == 0)
			return (&game->exit_open);
		else
			return (&game->exit_close);
	}
	else if (tile == OBSTACLE)
		return (&game->obstacle);
	return (NULL);
}

t_img	*get_tile2(t_game *game, char tile)
{
	if (tile == PLAYER)
	{
		if (game->player_pos.direction == 1)
			return (&game->player_left);
		else if (game->player_pos.direction == 2)
			return (&game->player_up);
		else if (game->player_pos.direction == 3)
			return (&game->player_right);
		else if (game->player_pos.direction == 4)
			return (&game->player_down);
	}
	else if (tile == MONSTER)
	{
		if (game->monsters[game->current_monster].direction == 1)
			return (&game->monster_left);
		else if (game->monsters[game->current_monster].direction == 2)
			return (&game->monster_right);
		game->current_monster++;
	}
	return (NULL);
}

int	render_map(t_game *game)
{
	int		i;
	int		j;
	t_img	*img;

	i = 0;
	game->current_monster = 0;
	draw_base(game);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			img = get_tile(game, game->map.grid[i][j]);
			if (!img)
				img = get_tile2(game, game->map.grid[i][j]);
			if (!img)
				exit_game(game, "Invalid map tile", ERROR);
			draw_img(game, img, i, j);
			blend_transparency(game, img, j * TILESIZE, i * TILESIZE);
			j++;
		}
		i++;
	}
	return (0);
}
