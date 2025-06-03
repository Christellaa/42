/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:59:50 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/14 13:14:11 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

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

void	push(t_stack **stack1, t_stack **stack2)
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
}

void	rotate(t_stack **stack1, t_stack **stack2, t_stacks *stacks)
{
	if (stack1 && *stack1 && (*stack1)->next != *stack1)
		*stack1 = (*stack1)->next;
	if (stack2 && *stack2 && (*stack2)->next != *stack2)
	{
		rotate(stack2, NULL, stacks);
		return ;
	}
}

void	rev_rotate(t_stack **stack1, t_stack **stack2, t_stacks *stacks)
{
	if (stack1 && *stack1 && (*stack1)->next != *stack1)
		*stack1 = (*stack1)->prev;
	if (stack2 && *stack2 && (*stack2)->next != *stack2)
	{
		rev_rotate(stack2, NULL, stacks);
		return ;
	}
}

void	swap(t_stack **stack1, t_stack **stack2, t_stacks *stacks)
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
		swap(stack2, NULL, stacks);
		return ;
	}
}
