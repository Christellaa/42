/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:30:58 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/23 11:27:39 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_files(int nb_args, int idx, int idx2, char **av)
{
	if (nb_args < idx && idx2 == 1)
	{
		ft_printf("Usage: %s infile cmd1 cmd2... cmdN outfile\n", av[0]);
		exit(EXIT_FAILURE);
	}
	if (nb_args < idx && idx2 == 2)
	{
		ft_printf("Usage: %s here_doc LIMITER cmd1 cmd2... cmdN outfile\n", \
				av[0]);
		exit(EXIT_FAILURE);
	}
}

char	*name_here_doc(void)
{
	int		fd;
	char	*name;

	fd = open("/dev/random", O_RDONLY);
	if (fd < 0)
		handle_error("Error: open /dev/random", NULL, 0, 0);
	name = ft_calloc(10, sizeof(char));
	if (!name)
		handle_error("Error: calloc name", NULL, 0, 0);
	read(fd, name, 10);
	close(fd);
	return (name);
}

int	handle_here_doc(char *delimiter, t_pipex *pipex)
{
	int		tmp_file;
	char	*line;

	tmp_file = open(pipex->here_doc, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_file < 0)
		return (-1);
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
	open(pipex->here_doc, O_RDONLY);
	return (tmp_file);
}

int	get_files(char **av, int idx, int flag, t_pipex *pipex)
{
	int	file;

	if (flag == 0)
		file = open(av[idx], O_RDONLY);
	else if (flag == 1)
		file = open(av[idx], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (flag == 2)
		file = handle_here_doc(av[idx + 1], pipex);
	else if (flag == 3)
		file = open(av[idx], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (file < 0 && (flag == 0 || flag == 2))
	{
		if (flag == 2)
			unlink(pipex->here_doc);
		handle_error("Error: open file", NULL, 0, 0);
	}
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
	if (nb_cmd == 0)
	{
		ft_printf("Error: find commands");
		exit(EXIT_FAILURE);
	}
	return (nb_cmd);
}
