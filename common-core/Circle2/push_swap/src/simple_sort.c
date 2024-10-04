/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:15:19 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/04 09:55:07 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3_numbers(t_stacks *stacks)
{
	if (!check_sorted(stacks))
		return ;
	find_min_max(stacks);
	if (stacks->min_nb == 1 && stacks->max_nb == 2)
		sa(stacks);
	else if (stacks->min_nb == 1 && stacks->max_nb == 0)
		ra(stacks);
	else if (stacks->min_nb == 2 && stacks->max_nb == 1)
		rra(stacks);
	else if (stacks->min_nb == 2 && stacks->max_nb == 0)
	{
		ra(stacks);
		sa(stacks);
	}
	else if (stacks->min_nb == 0)
	{
		rra(stacks);
		sa(stacks);
	}
}

void	sort_4_to_5_numbers(t_stacks *stacks)
{
	while (stacks->count > 3)
	{
		find_min_max(stacks);
		while (stacks->min_nb != 0)
		{
			if (stacks->min_nb >= 2)
				rra(stacks);
			else
				ra(stacks);
			find_min_max(stacks);
		}
		pb(stacks);
		stacks->size_b++;
		stacks->count--;
	}
	sort_3_numbers(stacks);
	while (stacks->size_b > 0)
	{
		pa(stacks);
		stacks->size_b--;
	}
}

void	simple_sort(t_stacks *stacks)
{
	if (stacks->count == 2)
		sa(stacks);
	else if (stacks->count == 3)
		sort_3_numbers(stacks);
	else if (stacks->count > 3)
		sort_4_to_5_numbers(stacks);
}
