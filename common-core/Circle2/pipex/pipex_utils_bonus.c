/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:58:05 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/10 13:50:42 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_files(int nb_args, int idx, int idx2, t_pipex *pipex)
{
	if (nb_args < idx && idx2 == 1)
		exit_process(pipex, NULL, USAGE);
	if (nb_args < idx && idx2 == 2)
		exit_process(pipex, NULL, USAGE_HERE_DOC);
}

void	name_here_doc(t_pipex *pipex)
{
	int		fd;
	char	*name;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		exit_process(pipex, NULL, "open /dev/urandom");
	name = ft_calloc(11, sizeof(char));
	if (!name)
	{
		close(fd);
		exit_process(pipex, NULL, "calloc here_doc name");
	}
	if (read(fd, name, 10) < 0)
	{
		free(name);
		close(fd);
		exit_process(pipex, NULL, "read /dev/urandom");
	}
	close(fd);
	pipex->here_doc = name;
}

int	handle_here_doc(char *delimiter, t_pipex *pipex)
{
	int		tmp_file;
	char	*line;

	tmp_file = open(pipex->here_doc, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_file < 0)
		exit_process(pipex, NULL, "open here_doc");
	while (1)
	{
		ft_putchar_fd('>', STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strequ(line, delimiter))
			break ;
		ft_putstr_fd(line, tmp_file);
		ft_putstr_fd("\n", tmp_file);
		free(line);
	}
	free(line);
	close(tmp_file);
	tmp_file = open(pipex->here_doc, O_RDONLY);
	return (tmp_file);
}
