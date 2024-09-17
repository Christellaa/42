/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:49:44 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/17 14:46:45 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define USAGE "Usage: ./pipex file1 cmd1 cmd2 file2"
# define USAGE_HERE_DOC "Usage: ./pipex_bonus here_doc LIMITER cmd1 cmd2 file2"

typedef struct s_cmd
{
	char			*name;
	char			**args;
	int				in;
	int				out;
	int				is_first;
	int				is_last;
	pid_t			pid;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipex
{
	char	**env;
	char	**paths;
	char	*here_doc;
	int		is_here_doc;
	int		infile;
	int		outfile;
	t_cmd	*cmds;
	int		cmd_start;
	int		cmd_end;
}	t_pipex;

// pipex_cleanup_bonus.c
void	free_groups(char **groups);
void	free_cmds(t_cmd *cmd);
void	print_msg(char *msg);
void	exit_process(t_pipex *pipex, char *msg);
void	init_pipex(t_pipex *pipex, int ac);
// pipex_paths_bonus.c
char	**get_paths(char **env);
char	*get_cmd_path(char *cmd, char **paths);
// pipex_cmds_bonus.c
char	**copy_args(char **args);
t_cmd	*create_cmd(char *cmd_path, char **args);
void	cmd_add_back(t_cmd **head, t_cmd *new);
t_cmd	*get_cmds(char **cmd, char **paths, t_pipex *pipex);
// pipex_children_bonus.c
void	create_pipes(t_cmd *cmd);
void	close_fds(t_cmd *cmd, t_pipex *pipex);
void	check_dup2(t_pipex *pipex, int fd, int std);
void	dup_files(t_cmd *cmd, t_pipex *pipex);
pid_t	child(t_cmd *cmd, t_pipex *pipex);
// pipex_utils_bonus.c
void	check_files(int nb_args, int idx, int idx2, t_pipex *pipex);
void	name_here_doc(t_pipex *pipex);
int		handle_here_doc(char *delimiter, t_pipex *pipex);

#endif