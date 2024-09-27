/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:18 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/25 10:47:13 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (stacks->stack_a && stacks->stack_a->next)
	{
		tmp = stacks->stack_a;
		tmp2 = stacks->stack_a->next;
		stacks->stack_a = tmp2;
		tmp->next = tmp2->next;
		tmp2->next = tmp;
	}
}

void	sb(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (stacks->stack_b && stacks->stack_b->next)
	{
		tmp = stacks->stack_b;
		tmp2 = stacks->stack_b->next;
		stacks->stack_b = tmp2;
		tmp->next = tmp2->next;
		tmp2->next = tmp;
	}
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}
