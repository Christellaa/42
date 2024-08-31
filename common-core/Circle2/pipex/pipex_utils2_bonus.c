/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:05:30 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/31 13:39:14 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_values(t_pipex *pipex)
{
	pipex->is_here_doc = 0;
	pipex->here_doc = NULL;
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->envp = NULL;
	pipex->nb_cmd = 0;
	pipex->current_cmd = 0;
	pipex->is_in_out.in = 0;
	pipex->is_in_out.out = 0;
}

void	check_dup2(int *pipefd, int fd, int target, t_pipex *pipex)
{
	if (fd < 0)
		exit_program(pipex, "fd", 1);
	if (dup2(fd, target) == -1)
	{
		close(fd);
		close(pipefd[0]);
		close(pipefd[1]);
		exit_program(pipex, "dup2", 1);
	}
}
