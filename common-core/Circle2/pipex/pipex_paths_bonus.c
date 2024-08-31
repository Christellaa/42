/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_paths_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:55:35 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/31 13:01:45 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_paths(t_pipex pipex)
{
	int		i;
	char	*paths;
	char	**split_paths;

	i = 0;
	paths = NULL;
	while (pipex.envp[i])
	{
		if (ft_strncmp(pipex.envp[i], "PATH=", 5) == 0)
		{
			paths = pipex.envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!paths)
		return (NULL);
	split_paths = ft_split(paths, ':');
	if (!split_paths)
		return (NULL);
	return (split_paths);
}

char	*find_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*tmp;
	char	*cmd_path;

	if (ft_strchr(cmd, '/') && access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (NULL);
		cmd_path = ft_strjoin_free_s1(tmp, cmd);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}
