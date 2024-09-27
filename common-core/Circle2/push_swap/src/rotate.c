/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:15:16 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/25 12:55:09 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


void	ra(t_stacks *stacks)
{
	t_list	*tmp;

	if (stacks->stack_a && stacks->stack_a->next)
	{
		tmp = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		ft_lstadd_back(&stacks->stack_a, tmp);
		tmp->next = NULL;
	}
}

void	rb(t_stacks *stacks)
{
	t_list	*tmp;

	if (stacks->stack_b && stacks->stack_b->next)
	{
		tmp = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
		ft_lstadd_back(&stacks->stack_b, tmp);
		tmp->next = NULL;
	}
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}
