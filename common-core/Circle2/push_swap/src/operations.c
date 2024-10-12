/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:15:34 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/12 14:29:57 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pop_head_stack1(t_stack **stack1, t_stack *tmp)
{
	if (*stack1 == (*stack1)->next)
		*stack1 = NULL;
	else
	{
		*stack1 = (*stack1)->next;
		(*stack1)->prev = tmp->prev;
		tmp->prev->next = *stack1;
	}
}

void	push(t_stack **stack1, t_stack **stack2, t_stacks *stacks,
		char *operation)
{
	t_stack	*tmp;

	if (!stack1 && !*stack1)
		return ;
	tmp = *stack1;
	pop_head_stack1(stack1, tmp);
	if (stack2 && *stack2)
	{
		tmp->next = *stack2;
		tmp->prev = (*stack2)->prev;
		(*stack2)->prev->next = tmp;
		(*stack2)->prev = tmp;
	}
	else
	{
		tmp->prev = tmp;
		tmp->next = tmp;
	}
	*stack2 = tmp;
	store_operation(stacks, operation);
}

void	rotate(t_stack **stack1, t_stack **stack2, t_stacks *stacks,
		char *operation)
{
	if (stack1 && *stack1 && (*stack1)->next != *stack1)
		*stack1 = (*stack1)->next;
	if (stack2 && *stack2 && (*stack2)->next != *stack2)
	{
		rotate(stack2, NULL, stacks, operation);
		return ;
	}
	store_operation(stacks, operation);
}

void	rev_rotate(t_stack **stack1, t_stack **stack2, t_stacks *stacks,
		char *operation)
{
	if (stack1 && *stack1 && (*stack1)->next != *stack1)
		*stack1 = (*stack1)->prev;
	if (stack2 && *stack2 && (*stack2)->next != *stack2)
	{
		rev_rotate(stack2, NULL, stacks, operation);
		return ;
	}
	store_operation(stacks, operation);
}

void	swap(t_stack **stack1, t_stack **stack2, t_stacks *stacks,
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
	if (stack2 && *stack2 && (*stack2)->next != *stack2)
	{
		swap(stack2, NULL, stacks, operation);
		return ;
	}
	store_operation(stacks, operation);
}
