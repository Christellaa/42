/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:26:46 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/29 15:57:04 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates a new string, which is the concatenation of s1 and s2
** Returns the new string, or NULL if the allocation fails
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*buffer;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	buffer = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	free((char *)s1);
	return (buffer);
}
