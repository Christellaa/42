/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:52:29 by cde-sous          #+#    #+#             */
/*   Updated: 2024/08/07 10:41:59 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

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

char	*ft_memcpy(char *dst, const char *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (n--)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s);
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s, len);
	s2[len] = '\0';
	return (s2);
}
