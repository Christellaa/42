/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:15:16 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/04 10:23:25 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ra(t_stacks *stacks)
{
	t_stack	*tmp;

	if (stacks->stack_a && stacks->stack_a->next)
	{
		tmp = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		ft_stackadd_back(&stacks->stack_a, tmp);
		tmp->next = NULL;
	}
	if (!stacks->is_double_operations)
		store_operation(stacks, "ra");
}

void	rb(t_stacks *stacks)
{
	t_stack	*tmp;

	if (stacks->stack_b && stacks->stack_b->next)
	{
		tmp = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
		ft_stackadd_back(&stacks->stack_b, tmp);
		tmp->next = NULL;
	}
	if (!stacks->is_double_operations)
		store_operation(stacks, "rb");
}

void	rr(t_stacks *stacks)
{
	stacks->is_double_operations = 1;
	ra(stacks);
	rb(stacks);
	store_operation(stacks, "rr");
}
