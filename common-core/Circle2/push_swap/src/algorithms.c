/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:02:22 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/04 12:38:40 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_sorted(t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = stacks->stack_a;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	index_numbers(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*compare;
	int		prev_count;

	tmp = stacks->stack_a;
	while (tmp)
	{
		prev_count = 0;
		compare = stacks->stack_a;
		while (compare)
		{
			if (*(int *)tmp->content > *(int *)compare->content)
				prev_count++;
			compare = compare->next;
		}
		tmp->idx = prev_count;
		tmp = tmp->next;
	}
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
	if (!check_sorted(stacks))
		cleanup(stacks, NULL, 1);
	index_numbers(stacks);
	if (stacks->count <= 5)
		simple_sort(stacks);
	else
		radix_sort(stacks);
}
