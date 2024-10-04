/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:47:41 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/04 10:23:16 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rra(t_stacks *stacks)
{
	t_stack	*last;
	t_stack	*second_last;

	if (stacks->stack_a && stacks->stack_a->next)
	{
		last = ft_stacklast(stacks->stack_a);
		second_last = stacks->stack_a;
		while (second_last->next->next)
			second_last = second_last->next;
		second_last->next = NULL;
		last->next = stacks->stack_a;
		stacks->stack_a = last;
	}
	if (!stacks->is_double_operations)
		store_operation(stacks, "rra");
}

void	rrb(t_stacks *stacks)
{
	t_stack	*last;
	t_stack	*second_last;

	if (stacks->stack_b && stacks->stack_b->next)
	{
		last = ft_stacklast(stacks->stack_b);
		second_last = stacks->stack_b;
		while (second_last->next->next)
			second_last = second_last->next;
		second_last->next = NULL;
		last->next = stacks->stack_b;
		stacks->stack_b = last;
	}
	if (!stacks->is_double_operations)
		store_operation(stacks, "rrb");
}

void	rrr(t_stacks *stacks)
{
	stacks->is_double_operations = 1;
	rra(stacks);
	rrb(stacks);
	store_operation(stacks, "rrr");
}
