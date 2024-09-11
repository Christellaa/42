/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:34:25 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/11 15:25:38 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

char	*gnl_newline(int fd)
{
	char	*line;
	char	*trimmed_line;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (NULL);
	if (line && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	trimmed_line = ft_strtrim(line, " ");
	free(line);
	return (trimmed_line);
}

int	open_fd(t_game *game, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_game(game, "Unable to open map file, does it exist?", ERROR);
	return (fd);
}

void	print_msg(char *msg, char *exit_type)
{
	char	*color;

	color = RESET;
	if (ft_strncmp(exit_type, ERROR, 5) == 0)
		color = RED;
	else if (ft_strncmp(exit_type, INFO, 4) == 0)
		color = YELLOW;
	ft_printf("%s%s%s\n%s", color, exit_type, msg, RESET);
}

void	check_map_line(t_game *game, int i)
{
	check_params(game, i);
	check_map_edges(game, i);
}

int	check_map_validity(t_game *game)
{
	check_last_line(game);
	if (game->map.validator.p_count != 1)
		exit_game(game, "Player count is not valid", ERROR);
	if (game->map.validator.e_count != 1)
		exit_game(game, "Exit count is not valid", ERROR);
	if (game->map.validator.c_count < 1)
		exit_game(game, "Collectible count is not valid", ERROR);
	check_map_rectangular(game);
	check_reachability(game);
	if (game->map.validator.e_reachable == 0)
		exit_game(game, "Exit is not reachable", ERROR);
	if (game->map.validator.c_reachable != game->map.validator.c_count)
		exit_game(game, "Collectibles are not reachable", ERROR);
	return (0);
}
