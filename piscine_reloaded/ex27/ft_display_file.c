/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:19:32 by cde-sous          #+#    #+#             */
/*   Updated: 2024/05/16 09:26:05 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_display_file(int ac, char **av)
{
	char	buffer[1];
	int		file_descriptor;

	if (ac != 2)
	{
		if (ac < 2)
			write(1, "File name missing.\n", 19);
		else
			write(1, "Too many arguments.\n", 20);
		return (1);
	}
	file_descriptor = open(av[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return (1);
	}
	while (read(file_descriptor, buffer, sizeof(buffer)))
		write(1, buffer, sizeof(buffer));
	close(file_descriptor);
	return (0);
}

int	main(int ac, char **av)
{
	ft_display_file(ac, av);
}
