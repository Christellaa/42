/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:02:22 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/09 10:45:41 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_sorted(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->idx > tmp->next->idx)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_inverse_sorted(t_stack *stack_b)
{
	t_stack	*tmp;

	tmp = stack_b;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content < *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	find_min_max(t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = stacks->stack_a;
	stacks->min_nb = tmp->idx;
	stacks->max_nb = tmp->idx;
	while (tmp)
	{
		if (tmp->idx < stacks->min_nb)
			stacks->min_nb = tmp->idx;
		if (tmp->idx > stacks->max_nb)
			stacks->max_nb = tmp->idx;
		tmp = tmp->next;
	}
}

void	algorithms(t_stacks *stacks)
{
	t_stack	*nb_max;

	nb_max = index_numbers(stacks->stack_a);
	if (check_sorted(stacks->stack_a))
		cleanup(stacks, NULL, 1);
	if (stacks->count <= 5)
		simple_sort(stacks);
	else
		radix_sort(stacks, nb_max);
}
