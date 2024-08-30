/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:30:58 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/30 11:54:18 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_files(int nb_args, int idx, int idx2, t_pipex *pipex)
{
	if (nb_args < idx && idx2 == 1)
		exit_program(pipex, USAGE, ERROR);
	if (nb_args < idx && idx2 == 2)
		exit_program(pipex, USAGE_HERE_DOC, ERROR);
}

void	name_here_doc(t_pipex *pipex)
{
	int		fd;
	char	*name;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		exit_program(pipex, "open /dev/urandom", ERROR);
	name = ft_calloc(11, sizeof(char));
	if (!name)
	{
		close(fd);
		exit_program(pipex, "calloc name", ERROR);
	}
	if (read(fd, name, 10) < 0)
	{
		free(name);
		close(fd);
		exit_program(pipex, "read /dev/urandom", ERROR);
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
		exit_program(pipex, "open here_doc", ERROR);
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

int	get_files(char **av, int idx, int flag, t_pipex *pipex)
{
	int	file;

	if (flag == 0)
	{
		file = open(av[idx], O_RDONLY);
		pipex->current_cmd = 2;
	}
	else if (flag == 1)
		file = open(av[idx], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (flag == 2)
	{
		file = handle_here_doc(av[idx + 1], pipex);
		pipex->current_cmd = 3;
	}
	else if (flag == 3)
		file = open(av[idx], O_CREAT | O_WRONLY | O_APPEND, 0644);
	return (file);
}

int	count_cmd(int ac, char **av)
{
	int	nb_cmd;
	int	i;

	nb_cmd = 0;
	i = 2;
	while (av[i] && i < ac - 1)
	{
		nb_cmd++;
		i++;
	}
	return (nb_cmd);
}
