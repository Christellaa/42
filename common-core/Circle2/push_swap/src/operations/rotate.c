/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:15:16 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/09 21:29:16 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate(t_stack **stack1, t_stack **stack2, t_stacks *stacks, \
			char *operation)
{
	t_stack	*tail;
	t_stack	*head;

	if (stack1 && *stack1 && (*stack1)->next != *stack1)
	{
		tail = (*stack1)->prev;
		head = tail->next;
		tail->next = head;
		head->prev = tail;
		(*stack1)->next = head->next;
		head->next->prev = *stack1;
		*stack1 = head;
	}
	if (stack1 && *stack1 && stack2 && *stack2 && (*stack2)->next != *stack2)
	{
		rotate(stack2, NULL, stacks, operation);
		return ;
	}
	else if (stack2 && *stack2 && (*stack2)->next != *stack2)
		rotate(stack1, stack2, stacks, operation);
	store_operation(stacks, operation);
}
