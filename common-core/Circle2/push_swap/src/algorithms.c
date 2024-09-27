/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:02:22 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/27 15:17:44 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	algorithms(t_stacks *stacks)
{
	if (stacks->count > SMALL_THRESHOLD)
		ft_printf("use radix sort: %d\n", stacks->count);
	else
		ft_printf("use insertion sort: %d\n", stacks->count);
}
