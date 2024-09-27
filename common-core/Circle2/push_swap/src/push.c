/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:15:34 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/25 12:37:00 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_stacks *stacks)
{
	t_list	*tmp;

	if (stacks->stack_b)
	{
		tmp = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
		tmp->next = stacks->stack_a;
		stacks->stack_a = tmp;
	}
}

void	pb(t_stacks *stacks)
{
	t_list	*tmp;

	if (stacks->stack_a)
	{
		tmp = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		tmp->next = stacks->stack_b;
		stacks->stack_b = tmp;
	}
}
