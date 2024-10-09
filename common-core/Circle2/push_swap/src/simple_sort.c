/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:15:19 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/09 21:57:29 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3_numbers(t_stacks *stacks)
{
	t_stack	*i;
	t_stack	*j;
	t_stack	*k;

	if (check_sorted(stacks->stack_a))
		return ;
	i = stacks->stack_a;
	j = i->next;
	k = j->next;
	if (i->idx > j->idx && j->idx < k->idx && i->idx < k->idx)
		swap(&stacks->stack_a, NULL, stacks, "sa");
	else if (i->idx > j->idx && j->idx < k->idx && i->idx > k->idx)
		rotate(&stacks->stack_a, NULL, stacks, "ra");
	else if (i->idx < j->idx && j->idx > k->idx && i->idx > k->idx)
		rev_rotate(&stacks->stack_a, NULL, stacks, "rra");
	else if (i->idx > j->idx && j->idx > k->idx && i->idx > k->idx)
	{
		rotate(&stacks->stack_a, NULL, stacks, "ra");
		swap(&stacks->stack_a, NULL, stacks, "sa");
	}
	else if (i->idx < j->idx && j->idx > k->idx && i->idx < k->idx)
	{
		rev_rotate(&stacks->stack_a, NULL, stacks, "rra");
		swap(&stacks->stack_a, NULL, stacks, "sa");
	}
}

int	get_pos_idx(t_stack *stack_a, int idx)
{
	int	pos;

	pos = 0;
	while (stack_a)
	{
		if (stack_a->idx == idx)
			break ;
		pos++;
		stack_a = stack_a->next;
	}
	return (pos);
}

void	sort_4_to_5_numbers(t_stacks *stacks)
{
	int	pos;
	int	idx;

	idx = 0;
	while (stacks->count > 3)
	{
		pos = get_pos_idx(stacks->stack_a, idx);
		while (stacks->stack_a->idx != idx)
		{
			if (pos >= 2)
				rev_rotate(&stacks->stack_a, NULL, stacks, "rra");
			else
				rotate(&stacks->stack_a, NULL, stacks, "ra");
		}
		push(&stacks->stack_a, &stacks->stack_b, stacks, "pb");
		stacks->size_b++;
		stacks->count--;
		idx++;
	}
	sort_3_numbers(stacks);
	while (stacks->size_b > 0)
	{
		push(&stacks->stack_b, &stacks->stack_a, stacks, "pa");
		stacks->size_b--;
	}
}

void	simple_sort(t_stacks *stacks)
{
	if (stacks->count == 2)
		swap(&stacks->stack_a, NULL, stacks, "sa");
	else if (stacks->count == 3)
		sort_3_numbers(stacks);
	else if (stacks->count > 3)
		sort_4_to_5_numbers(stacks);
}
