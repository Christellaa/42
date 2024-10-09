/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:18 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/09 21:09:49 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_stack **stack1, t_stack **stack2, t_stacks *stacks, \
			char *operation)
{
	t_stack	*first;
	t_stack	*second;

	if (stack1 && *stack1 && (*stack1)->next != *stack1)
	{
		first = *stack1;
		second = first->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->next = first;
		second->prev = first->prev;
		if (first->prev)
			first->prev->next = second;
		first->prev = second;
		*stack1 = second;
	}
	if (stack1 && *stack1 && stack2 && *stack2 && (*stack2)->next != *stack2)
	{
		swap(stack2, NULL, stacks, operation);
		return ;
	}
	else if (stack2 && *stack2 && (*stack2)->next != *stack2)
		swap(stack1, stack2, stacks, operation);
	store_operation(stacks, operation);
}
