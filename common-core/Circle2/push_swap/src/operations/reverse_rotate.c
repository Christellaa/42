/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:47:41 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/09 21:22:47 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rev_rotate(t_stack **stack1, t_stack **stack2, t_stacks *stacks, \
				char *operation)
{
	t_stack	*tail;
	t_stack	*head;

	if (stack1 && *stack1 && (*stack1)->next != *stack1)
	{
		tail = (*stack1)->prev;
		head = tail->prev;
		tail->next = *stack1;
		(*stack1)->prev = tail;
		(*stack1)->next = head;
		head->prev = *stack1;
		(*stack1) = head;
	}
	if (stack1 && *stack1 && stack2 && *stack2 && (*stack2)->next != *stack2)
	{
		rev_rotate(stack2, NULL, stacks, operation);
		return ;
	}
	else if (stack2 && *stack2 && (*stack2)->next != *stack2)
		rev_rotate(stack1, stack2, stacks, operation);
	store_operation(stacks, operation);
}
