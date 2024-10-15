/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:14:53 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/14 17:49:39 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptrs1;
	const unsigned char	*ptrs2;
	size_t				i;

	ptrs1 = (const unsigned char *)s1;
	ptrs2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && ptrs1[i] == ptrs2[i])
		i++;
	return (ptrs1[i] - ptrs2[i]);
}
