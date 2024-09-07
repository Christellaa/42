/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:57:48 by cde-sous          #+#    #+#             */
/*   Updated: 2024/05/21 15:26:29 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copy from string s to a new string
** Returns a pointer to the new string, or NULL if the allocation fails
** 
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		size;
	int		i;

	size = ft_strlen(s);
	new = malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}