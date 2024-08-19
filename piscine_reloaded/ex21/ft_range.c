/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:18:41 by cde-sous          #+#    #+#             */
/*   Updated: 2024/05/14 15:51:02 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int	size;

	i = 0;
	size = max - min;
	range = (int *) malloc(size * sizeof (int));
	if (min >= max || range == NULL)
		return (NULL);
	while (i < size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
