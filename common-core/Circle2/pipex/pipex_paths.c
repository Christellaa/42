/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:07:01 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/10 15:22:34 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **env)
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(env[i] + 5);
			if (!path)
				return (NULL);
			paths = ft_split(path, ':');
			free(path);
			return (paths);
		}
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*tmp;
	char	*path;

	if ((ft_strncmp(cmd, "/", 1) == 0 || ft_strncmp(cmd, "./", 2) == 0) \
	&& access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	i = 0;
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (NULL);
		path = ft_strjoin_free_s1(tmp, cmd);
		if (!path)
			return (NULL);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
