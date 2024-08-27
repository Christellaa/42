/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:29:55 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/27 16:52:31 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"

# define USAGE "Usage: ./pipex file1 cmd1 cmd2 file2"
# define ERROR	"Error"
# define INFO	"Info"
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define RESET	"\033[0m"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	**envp;
}	t_pipex;

// paths.c
char	**get_paths(t_pipex pipex);
char	*find_cmd_path(t_pipex *pipex, char *cmd, char **paths);
// cleanup.c
void	print_msg(char *msg, char *exit_type);
void	exit_program(t_pipex *pipex, char *msg, char *exit_type);
void	free_groups(char **group1, char **group2);

#endif
