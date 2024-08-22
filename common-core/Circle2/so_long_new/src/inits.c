/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:50:48 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/22 18:24:39 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	init_img(t_game *game, char *path)
{
	game->image.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&game->image.width, &game->image.height);
	if (!game->image.img_ptr)
		handle_error("Error during image initialization\n", -1, game, NULL);
	game->image.data = mlx_get_data_addr(game->image.img_ptr,
			&game->image.bpp, &game->image.sizeline, &game->image.endian);
	if (!game->image.data)
		handle_error("Error during image initialization\n", -1, game, NULL);
}

void	init_imgs(t_game *game)
{
	init_img(game, FLOOR_XPM);
	init_img(game, WALL_XPM);
	init_img(game, COLLECTIBLE_XPM);
	init_img(game, EXIT_XPM);
	init_img(game, PLAYER_XPM);
}

int	init_game(t_game *game, char *filename)
{
	get_map_dimensions(game, filename);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		handle_error("Error during mlx initialization\n", -1, game, NULL);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * TILESIZE,
			game->height * TILESIZE, "so_long");
	if (!game->win_ptr)
		handle_error("Error during window creation\n", -1, game, NULL);
	init_imgs(game);
	game->player.x = 0;
	game->player.y = 0;
	game->map.validator.p_count = 0;
	game->map.validator.e_count = 0;
	game->map.validator.c_count = 0;
	game->map.validator.e_reachable = 0;
	game->map.validator.c_reachable = 0;
	return (0);
}
