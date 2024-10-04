/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:02:22 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/04 10:19:12 by cde-sous         ###   ########.fr       */
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
		tmp->idx = -1;
		tmp = tmp->next;
	}
	tmp->idx = -1;
	return (0);
}

void	find_min_max(t_stacks *stacks)
{
	t_stack	*tmp;
	int		pos;
	int		min_value;
	int		max_value;

	tmp = stacks->stack_a;
	min_value = *(int *)tmp->content;
	max_value = *(int *)tmp->content;
	re_init_values(stacks);
	pos = 0;
	while (tmp)
	{
		if (*(int *)tmp->content < min_value)
		{
			min_value = *(int *)tmp->content;
			stacks->min_nb = pos;
		}
		if (*(int *)tmp->content > max_value)
		{
			max_value = *(int *)tmp->content;
			stacks->max_nb = pos;
		}
		tmp = tmp->next;
		pos++;
	}
}

void	algorithms(t_stacks *stacks)
{
	if (!check_sorted(stacks))
		cleanup(stacks, NULL, 1);
	if (stacks->count <= 5)
		simple_sort(stacks);
	else
		radix_sort(stacks);
}
