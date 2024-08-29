/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:29:55 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/29 18:03:47 by cde-sous         ###   ########.fr       */
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
	int		current_cmd;
}	t_pipex;

// utils_bonus.c
void	check_files(int nb_args, int idx, int idx2, t_pipex *pipex);
void	name_here_doc(t_pipex *pipex);
int		handle_here_doc(char *delimiter, t_pipex *pipex);
int		get_files(char **av, int idx, int flag, t_pipex *pipex);
int		count_cmd(t_pipex *pipex, int ac, char **av);
// paths_bonus.c
char	**get_paths(t_pipex pipex);
char	*find_cmd_path(t_pipex *pipex, char *cmd, char **paths);
// cleanup_bonus.c
void	init_values(t_pipex *pipex);
void	print_msg(char *msg, char *exit_type);
void	exit_program(t_pipex *pipex, char *msg, char *exit_type);
void	free_groups(char **group1, char **group2);
void	close_here_doc(t_pipex pipex);

#endif
