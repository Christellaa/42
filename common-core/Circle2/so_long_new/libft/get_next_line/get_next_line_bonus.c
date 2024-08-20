/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:52:14 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/05 15:59:34 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char **buf)
{
	char	*line;
	char	*ptr_buf;

	ptr_buf = *buf;
	while (*ptr_buf != '\n' && *ptr_buf != '\0')
		ptr_buf++;
	ptr_buf += (*ptr_buf == '\n');
	line = ft_substr(*buf, 0, (size_t)(ptr_buf - *buf));
	if (!line)
	{
		free(*buf);
		return (NULL);
	}
	ptr_buf = ft_strdup(ptr_buf);
	free(*buf);
	*buf = ptr_buf;
	return (line);
}

static char	*read_line(int fd, char *buf, char *line)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, line, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		line[bytes_read] = '\0';
		buf = ft_strjoin_free_s1(buf, line);
		if (ft_strchr(line, '\n') || ft_strchr(line, '\0'))
			break ;
		bytes_read = read(fd, line, BUFFER_SIZE);
	}
	free(line);
	if (bytes_read < 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf[fd])
		buf[fd] = ft_strdup("");
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
	{
		free(buf[fd]);
		return (NULL);
	}
	buf[fd] = read_line(fd, buf[fd], line);
	if (!buf[fd] || !*buf[fd])
	{
		free(buf[fd]);
		buf[fd] = NULL;
		return (NULL);
	}
	return (extract_line(&buf[fd]));
}
