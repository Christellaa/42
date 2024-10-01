/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:15:19 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/01 14:17:15 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3_numbers(t_stacks *stacks)
{
	if (!check_sorted(stacks))
		return ;
	find_min_max(stacks);
	if (stacks->min == 1)
	{
		if (stacks->max == 2)
			sa(stacks);
		else if (stacks->max == 0)
			ra(stacks);
	}
	else if (stacks->min == 2)
	{
		if (stacks->max == 1)
			rra(stacks);
		else if (stacks->max == 0)
		{
			ra(stacks);
			sa(stacks);
		}
	}
	else if (stacks->min == 0)
	{
		rra(stacks);
		sa(stacks);
	}
}

void	sort_4_numbers(t_stacks *stacks)
{
	find_min_max(stacks);
	if (stacks->min >= 2)
	{
		while (stacks->min != 4)
		{
			rra(stacks);
			stacks->min++;
		}
	}
	else
	{
		while (stacks->min != 0)
		{
			ra(stacks);
			stacks->min--;
		}
	}
	pb(stacks);
	sort_3_numbers(stacks);
	pa(stacks);
}

void	sort_5_numbers(t_stacks *stacks)
{
	find_min_max(stacks);
	if (stacks->min >= 2)
	{
		while (stacks->min != 5)
		{
			rra(stacks);
			stacks->min++;
		}
	}
	else
	{
		while (stacks->min != 0)
		{
			ra(stacks);
			stacks->min--;
		}
	}
	pb(stacks);
	sort_4_numbers(stacks);
	pa(stacks);
}

void	simple_sort(t_stacks *stacks)
{
	if (stacks->count == 2)
		sa(stacks);
	else if (stacks->count == 3)
		sort_3_numbers(stacks);
	else if (stacks->count == 4)
		sort_4_numbers(stacks);
	else if (stacks->count == 5)
		sort_5_numbers(stacks);
}
