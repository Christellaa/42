/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:50:48 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/24 15:55:23 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

char	*gnl_newline(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

void	get_map_dimensions(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Error while opening file\n", -1, game, NULL);
	game->width = 0;
	game->height = 0;
	line = gnl_newline(fd);
	while (line)
	{
		if (game->width == 0)
			game->width = ft_strlen(line);
		else if (game->width != (int)ft_strlen(line))
			handle_error("Invalid map dimensions\n", -1, game, NULL);
		game->height++;
		free(line);
		line = gnl_newline(fd);
	}
	free(line);
	close(fd);
}

void	init_img(t_game *game, t_img *img, char *path)
{
	img->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&img->width, &img->height);
	if (!img->img_ptr)
		handle_error("Error during image initialization\n", -1, game, NULL);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->sizeline, &img->endian);
	if (!img->data)
		handle_error("Error during image initialization\n", -1, game, NULL);
}

int	init_imgs(t_game *game)
{
	init_img(game, &game->floor, FLOOR_XPM);
	init_img(game, &game->wall, WALL_XPM);
	init_img(game, &game->collectible, COLLECTIBLE_XPM);
	init_img(game, &game->exit, EXIT_XPM);
	init_img(game, &game->player, PLAYER_DOWN_XPM);
	init_img(game, &game->monster, MONSTER_LEFT_XPM);
	init_img(game, &game->obstacle, OBSTACLE_XPM);
	return (1);
}

int	init_game(t_game *game, char *filename)
{
	get_map_dimensions(game, filename);
	game->map.grid = ft_calloc(sizeof(char *), (game->height + 1));
	if (!game->map.grid)
		handle_error("Error while allocating memory to grid", 0, NULL, NULL);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		handle_error("Error during mlx initialization\n", -1, game, NULL);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILESIZE,
			game->height * TILESIZE, "so_long");
	if (!game->win_ptr)
		handle_error("Error during window creation\n", -1, game, NULL);
	if (!init_imgs(game))
		handle_error("Error during image initialization\n", -1, game, NULL);
	game->player_pos.x = -1;
	game->player_pos.y = -1;
	game->monster_count = 0;
	game->current_monster = 0;
	game->map.validator.p_count = 0;
	game->map.validator.e_count = 0;
	game->map.validator.c_count = 0;
	game->map.validator.e_reachable = 0;
	game->map.validator.c_reachable = 0;
	game->move_count = 0;
	return (0);
}
