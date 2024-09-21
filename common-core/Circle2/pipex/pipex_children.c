/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_children.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:02:24 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/21 19:34:03 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipes(t_cmd *cmd)
{
	t_cmd	*current;
	int		pipefd[2];

	current = cmd;
	while (current)
	{
		if (current->is_first)
			current->in = -1;
		current->out = -1;
		if (current->next)
		{
			if (pipe(pipefd) == -1)
				exit_process(NULL, "Pipe");
			current->out = pipefd[1];
			current->next->in = pipefd[0];
		}
		current = current->next;
	}
}

void	close_fds(t_cmd *cmd, t_pipex *pipex)
{
	while (cmd)
	{
		if (cmd->in > 0)
			close(cmd->in);
		if (cmd->out > 0)
			close(cmd->out);
		cmd = cmd->next;
	}
	if (pipex->infile > 0)
		close(pipex->infile);
	if (pipex->outfile > 0)
		close(pipex->outfile);
}

void	check_dup2(t_pipex *pipex, int fd, int std)
{
	if (dup2(fd, std) == -1)
		exit_process(pipex, NULL);
}

void	dup_files(t_cmd *cmd, t_pipex *pipex)
{
	int	null_fd;

	if (cmd->is_first && pipex->infile > 0)
		check_dup2(pipex, pipex->infile, STDIN_FILENO);
	else if (cmd->in == -1)
	{
		null_fd = open("/dev/null", O_RDONLY);
		if (null_fd == -1)
			exit_process(pipex, "Open /dev/null");
		check_dup2(pipex, null_fd, STDIN_FILENO);
		close(null_fd);
	}
	else
		check_dup2(pipex, cmd->in, STDIN_FILENO);
	if (cmd->is_last && pipex->outfile > 0)
		check_dup2(pipex, pipex->outfile, STDOUT_FILENO);
	else
		check_dup2(pipex, cmd->out, STDOUT_FILENO);
	close_fds(pipex->cmds, pipex);
}

pid_t	child(t_cmd *cmd, t_pipex *pipex)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_process(pipex, "Fork");
	if (pid == 0)
	{
		dup_files(cmd, pipex);
		if (cmd->name == NULL)
			exit_process(pipex, cmd->name);
		if (execve(cmd->name, cmd->args, pipex->env) == -1)
			exit_process(pipex, cmd->name);
	}
	return (pid);
}
