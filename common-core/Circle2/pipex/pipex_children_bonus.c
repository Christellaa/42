/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_children_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 12:02:24 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/10 14:56:37 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_pipes(t_cmd *cmd)
{
	t_cmd	*current;
	int		pipefd[2];

	current = cmd;
	while (current && current->next)
	{
		if (pipe(pipefd) == -1)
			exit_process(NULL, current, "Pipe");
		current->out = pipefd[1];
		current->next->in = pipefd[0];
		current = current->next;
	}
}

void	check_dup2(t_pipex *pipex, int fd, int std)
{
	if (dup2(fd, std) == -1)
		exit_process(pipex, NULL, NULL);
}

void	dup_files(t_cmd *cmd, t_pipex *pipex)
{
	if (cmd->is_first)
	{
		check_dup2(pipex, pipex->infile, STDIN_FILENO);
		close(pipex->infile);
	}
	else
		check_dup2(pipex, cmd->in, STDIN_FILENO);
	if (cmd->is_last)
		check_dup2(pipex, pipex->outfile, STDOUT_FILENO);
	else
		check_dup2(pipex, cmd->out, STDOUT_FILENO);
	if (pipex->outfile > 0)
		close(pipex->outfile);
	while (cmd->next)
	{
		if (!cmd->is_first)
			close(cmd->in);
		close(cmd->out);
		cmd = cmd->next;
	}
}

pid_t	child(t_cmd *cmd, t_pipex *pipex)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_process(pipex, cmd, "Fork");
	if (pid == 0)
	{
		dup_files(cmd, pipex);
		if (execve(cmd->name, cmd->args, pipex->env) == -1)
			exit_process(pipex, cmd, cmd->name);
	}
	if (cmd->is_first && pipex->infile > 0)
		close(pipex->infile);
	if (cmd->is_last && pipex->outfile > 0)
		close(pipex->outfile);
	if (!cmd->is_first)
		close(cmd->in);
	if (!cmd->is_last)
		close(cmd->out);
	return (pid);
}
