/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:32:10 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/24 13:41:34 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	g_state = 0;

#define MULTIPLIER 1103515245
#define INCREMENT 12345
#define MODULUS (2147483648)

// Generate the next random number
static unsigned int	next_rng(void)
{
	g_state = (g_state * MULTIPLIER + INCREMENT) % MODULUS;
	return (g_state);
}

// Generate a random number between min and max
unsigned int	ft_rand(unsigned int min, unsigned int max)
{
	unsigned int	range;
	int				fd;

	if (g_state == 0)
	{
		fd = open("/dev/random", O_RDONLY);
		if (fd < 0)
			return (0);
		read(fd, &g_state, sizeof(g_state));
		close(fd);
	}
	range = max - min + 1;
	return (min + next_rng() % range);
}
