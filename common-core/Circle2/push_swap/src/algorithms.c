/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:02:22 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/27 15:56:25 by cde-sous         ###   ########.fr       */
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

void	insertion_sort(t_stacks *stacks)
{
	t_list	*sorted;
	t_list	*tmp;
	t_list	*next;

	sorted = NULL;
	while (stacks->stack_a)
	{
		next = stacks->stack_a->next;
		if (sorted == NULL || sorted->content >= stacks->stack_a->content)
		{
			stacks->stack_a->next = sorted;
			sorted = stacks->stack_a;
		}
		else
		{
			tmp = sorted;
			while (tmp->next && tmp->next->content < stacks->stack_a->content)
				tmp = tmp->next;
			stacks->stack_a->next = tmp->next;
			tmp->next = stacks->stack_a;
		}
		stacks->stack_a = next;
	}
	stacks->stack_a = sorted;
}
