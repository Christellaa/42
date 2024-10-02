/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:02:22 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/02 14:02:49 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_sorted(t_stacks *stacks)
{
	t_list	*tmp;

	tmp = stacks->stack_a;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	find_min_max(t_stacks *stacks)
{
	t_list	*tmp;
	int		pos;
	int		nb_min;
	int		nb_max;

	tmp = stacks->stack_a;
	nb_min = *(int *)tmp->content;
	nb_max = *(int *)tmp->content;
	pos = 0;
	while (tmp)
	{
		if (*(int *)tmp->content < nb_min)
		{
			nb_min = *(int *)tmp->content;
			stacks->min = pos;
		}
		if (*(int *)tmp->content > nb_max)
		{
			nb_max = *(int *)tmp->content;
			stacks->max = pos;
		}
		tmp = tmp->next;
		pos++;
	}
}

void	algorithms(t_stacks *stacks)
{
	if (!check_sorted(stacks))
		cleanup(stacks->stack_a, stacks->stack_b, NULL, 1);
	if (stacks->count <= 5)
		simple_sort(stacks);
	/* else
		radix_sort(stacks); */
	print_all(stacks);
}
