/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:26:43 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/14 17:50:22 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	buffer = malloc((nmemb * size));
	if (!buffer)
		return (NULL);
	ft_memset(buffer, 0, nmemb * size);
	return (buffer);
}
