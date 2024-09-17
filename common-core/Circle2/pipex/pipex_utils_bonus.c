/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:58:05 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/17 14:54:35 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_files(int nb_args, int idx, int idx2, t_pipex *pipex)
{
	if (nb_args < idx && idx2 == 1)
		exit_process(pipex, USAGE);
	if (nb_args < idx && idx2 == 2)
		exit_process(pipex, USAGE_HERE_DOC);
}

void	name_here_doc(t_pipex *pipex)
{
	int		fd;
	char	*name;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		exit_process(pipex, "open /dev/urandom");
	name = ft_calloc(11, sizeof(char));
	if (!name)
	{
		close(fd);
		exit_process(pipex, "calloc here_doc name");
	}
	if (read(fd, name, 10) < 0)
	{
		free(name);
		close(fd);
		exit_process(pipex, "read /dev/urandom");
	}
	close(fd);
	pipex->here_doc = name;
}

int	process_line(char *line, char *delimiter, int tmp_file, int *line_nb)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (ft_strequ(line, delimiter))
		return (0);
	ft_putstr_fd(line, tmp_file);
	ft_putstr_fd("\n", tmp_file);
	free(line);
	(*line_nb)++;
	return (1);
}

int	handle_here_doc(char *delimiter, t_pipex *pipex)
{
	int		tmp_file;
	char	*line;
	int		line_nb;

	tmp_file = open(pipex->here_doc, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_file < 0)
		exit_process(pipex, "open here_doc");
	line_nb = 1;
	while (1)
	{
		ft_putchar_fd('>', STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			ft_printf("\nwarning: here-document at line %d ", line_nb);
			ft_printf("delimited by end of file (wanted '%s')\n", delimiter);
			break ;
		}
		if (!process_line(line, delimiter, tmp_file, &line_nb))
			break ;
	}
	free(line);
	close(tmp_file);
	return (open(pipex->here_doc, O_RDONLY));
}
