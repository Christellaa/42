/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:29:55 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/23 10:47:21 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	int		infile;
	int		outfile;
	char	**envp;
}	t_pipex;

// paths.c
char	**get_paths(t_pipex pipex);
char	*find_cmd_path(char *cmd, char **paths);
// cleanup.c
void	handle_error(char *msg, char *to_free, int fd1, int fd2);
void	free_group(char **group1, char **group2);

#endif
