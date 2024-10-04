/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:55:20 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/04 10:52:39 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	index_numbers(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*compare;
	int		prev_count;

	tmp = stacks->stack_a;
	while (tmp)
	{
		prev_count = 0;
		compare = stacks->stack_a;
		while (compare)
		{
			if (*(int *)tmp->content > *(int *)compare->content)
				prev_count++;
			compare = compare->next;
		}
		tmp->idx = prev_count;
		tmp = tmp->next;
	}
}

void	radix_sort(t_stacks *stacks)
{
	index_numbers(stacks);
}
