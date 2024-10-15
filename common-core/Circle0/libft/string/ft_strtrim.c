/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:46:54 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/14 19:14:58 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	newstr = malloc((end - start + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (start < end)
		newstr[i++] = s1[start++];
	newstr[i] = '\0';
	return (newstr);
}
