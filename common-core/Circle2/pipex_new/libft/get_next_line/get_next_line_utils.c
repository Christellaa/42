/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:52:29 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/13 19:27:31 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free_s1(char *s1, char const *s2)
{
	char	*s3;
	char	*ptr3;
	char	*ptr1;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
	{
		free(s1);
		return (NULL);
	}
	ptr3 = s3;
	ptr1 = s1;
	while (*ptr1)
		*ptr3++ = *ptr1++;
	while (*s2)
		*ptr3++ = *s2++;
	*ptr3 = '\0';
	free(s1);
	return (s3);
}
