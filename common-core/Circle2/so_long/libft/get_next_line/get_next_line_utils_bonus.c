/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:52:20 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/05 15:41:07 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_free_s1(char *s1, char const *s2)
{
	char	*s3;
	char	*ptr3;
	char	*ptr1;

	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*s3));
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
