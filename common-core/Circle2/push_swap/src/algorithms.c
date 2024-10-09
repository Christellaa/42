/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:02:22 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/09 20:36:05 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_sorted(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp && tmp->next != stack_a)
	{
		if (tmp->idx > tmp->next->idx)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->idx < stack_a->idx)
		return (0);
	return (1);
}

void	find_min_max(t_stacks *stacks)
{
	t_stack	*tmp;
	int		first_iteration;

	tmp = stacks->stack_a;
	stacks->min_nb = tmp->idx;
	stacks->max_nb = tmp->idx;
	first_iteration = 1;
	while (tmp)
	{
		if (tmp->idx < stacks->min_nb)
			stacks->min_nb = tmp->idx;
		if (tmp->idx > stacks->max_nb)
			stacks->max_nb = tmp->idx;
		tmp = tmp->next;
		if (tmp == stacks->stack_a && !first_iteration)
			break ;
		first_iteration = 0;
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
