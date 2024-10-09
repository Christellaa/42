/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:15:34 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/09 21:51:59 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push(t_stack **stack1, t_stack **stack2, t_stacks *stacks, \
			char *operation)
{
	t_stack	*tmp;

	if (stack1 && *stack1)
	{
		tmp = *stack1;
		*stack1 = (*stack1)->next;
		if (*stack1 && (*stack1) != tmp)
			(*stack1)->prev = tmp->prev;
		else
			*stack1 = NULL;
		tmp->next = *stack2;
		if (stack2 && *stack2)
		{
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
	store_operation(stacks, operation);
}
