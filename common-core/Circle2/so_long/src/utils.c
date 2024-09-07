/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:18:48 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/07 18:54:03 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*gnl_newline(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line && line[ft_strlen(line) - 1] == '\n' && ft_strlen(line) > 1)
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

int	open_fd(t_game *game, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_game(game, "Unable to open map file", ERROR);
	return (fd);
}

void	check_map_line(t_game *game, int i)
{
	check_params(game, i);
	check_map_edges(game, i);
}

void	print_msg(char *msg, char *exit_type)
{
	char	*color;

	color = RESET;
	if (ft_strncmp(exit_type, ERROR, 5) == 0)
		color = RED;
	else if (ft_strncmp(exit_type, INFO, 4) == 0)
		color = YELLOW;
	ft_printf("%s%s: %s\n%s", color, exit_type, msg, RESET);
}
