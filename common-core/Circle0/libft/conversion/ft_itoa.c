/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:45:34 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/14 19:23:05 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// count the number of digits in the number
static int	count_digits(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

// reverse the string to get the numbers in order
static void	reverse(char *s, int len, int is_negative)
{
	int		start;
	int		end;
	char	temp;

	if (is_negative == 1)
		start = 1;
	else
		start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}

// convert the number to a string
static char	*convert(int n, char *s)
{
	int	i;
	int	is_negative;

	i = 0;
	is_negative = 0;
	if (n == 0)
		return (ft_strcpy(s, "0"));
	if (n < 0)
	{
		is_negative = 1;
		s[i++] = '-';
		if (n == -2147483648)
		{
			return (ft_strcpy(s, "-2147483648"));
		}
		n = -n;
	}
	while (n > 0)
	{
		s[i++] = n % 10 + '0';
		n /= 10;
	}
	s[i] = '\0';
	reverse(s, i, is_negative);
	return (s);
}

char	*ft_itoa(int n)
{
	char	*to_ascii;

	to_ascii = malloc((count_digits(n) + 1) * sizeof(char));
	if (!to_ascii)
		return (NULL);
	convert(n, to_ascii);
	return (to_ascii);
}
