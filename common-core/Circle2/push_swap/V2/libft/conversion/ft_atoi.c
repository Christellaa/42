/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:50:15 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/18 16:11:54 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Converts the ASCII string pointed to by nptr to an int value.
** Returns the converted value, or 0 on error
*/

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i++] - '0';
		if ((res > INT_MAX && sign == 1) || (res > (long)INT_MAX + 1 && sign ==
				-1))
			return (0);
	}
	if (nptr[i])
		return (0);
	return (sign * res);
}
