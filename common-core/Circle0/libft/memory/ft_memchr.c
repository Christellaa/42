/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:44:02 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/14 17:48:56 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptrs;
	size_t				i;

	ptrs = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptrs[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
