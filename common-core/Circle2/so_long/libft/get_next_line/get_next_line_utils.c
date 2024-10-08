/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:52:29 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/06 20:26:52 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin_free_s1(char *s1, char const *s2, size_t len)
{
	char	*new_s;
	size_t	len_s1;

	if (s1)
		len_s1 = ft_strlen(s1);
	else
		len_s1 = 0;
	new_s = malloc(len_s1 + len + 1);
	if (!new_s)
		return (NULL);
	if (s1)
	{
		ft_memcpy(new_s, s1, len_s1);
		free(s1);
	}
	if (s2)
		ft_memcpy(new_s + len_s1, s2, len);
	new_s[len_s1 + len] = '\0';
	return (new_s);
}
