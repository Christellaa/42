/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:29:55 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/07 13:51:59 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <err.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"

typedef struct s_pipex
{
	int		is_here_doc;
	int		inputfile;
	int		outputfile;
	char	**envp;
	int		nb_cmd;
	int		current_cmd;
}	t_pipex;

// utils.c
void	check_files(int nb_args, int idx, int idx2, char **av);
int		handle_here_doc(char *delimiter);
int		get_files(char **av, int idx, int flag);
int		count_cmd(int ac, char **av);
// paths.c
char	**get_paths(t_pipex pipex);
char	*find_cmd_path(char *cmd, char **paths);
// cleanup.c
void	handle_error(char *msg, char *to_free, int fd1, int fd2);
void	free_group(char **group);

#endif