/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:07:36 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/13 17:45:53 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*find_cheapest_number(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*cheapest;

	tmp = stacks->stack_b;
	cheapest = tmp;
	while (tmp)
	{
		if (tmp->moves < cheapest->moves)
			cheapest = tmp;
		tmp = tmp->next;
		if (tmp == stacks->stack_b)
			break ;
	}
	return (cheapest);
}

void	push_cheapest_number(t_stacks *stacks, t_stack *cheapest, int median_b,
		int median_a)
{
	if (cheapest->idx != 0 && cheapest->target->idx != 0
		&& cheapest->idx > median_b && cheapest->target->idx > median_a)
		rev_rotate(&stacks->stack_a, &stacks->stack_b, stacks, "rrr");
	else if (cheapest->idx != 0 && cheapest->target->idx != 0
		&& cheapest->idx <= median_b && cheapest->target->idx <= median_a)
		rotate(&stacks->stack_a, &stacks->stack_b, stacks, "rr");
	else
	{
		if (cheapest->idx != 0 && cheapest->idx > median_b)
			rev_rotate(&stacks->stack_b, NULL, stacks, "rrb");
		else if (cheapest->idx != 0 && cheapest->idx <= median_b)
			rotate(&stacks->stack_b, NULL, stacks, "rb");
		else if (cheapest->target->idx != 0 && cheapest->target->idx > median_a)
			rev_rotate(&stacks->stack_a, NULL, stacks, "rra");
		else if (cheapest->target->idx != 0
			&& cheapest->target->idx <= median_a)
			rotate(&stacks->stack_a, NULL, stacks, "ra");
	}
	index_numbers(stacks->stack_a);
	index_numbers(stacks->stack_b);
}

void	push_to_stack_a(t_stacks *stacks)
{
	int		len;
	int		median_stack_a;
	int		median_stack_b;
	t_stack	*cheapest;

	len = ft_stacksize(stacks->stack_b);
	while (len-- > 0)
	{
		index_numbers(stacks->stack_a);
		index_numbers(stacks->stack_b);
		get_target(stacks);
		median_stack_a = get_median(stacks->stack_a);
		median_stack_b = get_median(stacks->stack_b);
		get_min_moves(stacks, median_stack_a, median_stack_b);
	}
	cheapest = find_cheapest_number(stacks);
	while (cheapest->idx != 0 || cheapest->target->idx != 0)
	{
		push_cheapest_number(stacks, cheapest, median_stack_b, median_stack_a);
		if (cheapest->idx == 0 && cheapest->target->idx == 0)
			break ;
	}
	push(&stacks->stack_b, &stacks->stack_a, stacks, "pa");
}

void	move_to_stack_b(int len_stack_a, int median_stack_a, t_stacks *stacks)
{
	while (len_stack_a > 3)
	{
		if (stacks->stack_a->content < median_stack_a)
			push(&stacks->stack_a, &stacks->stack_b, stacks, "pb");
		else
		{
			push(&stacks->stack_a, &stacks->stack_b, stacks, "pb");
			rotate(&stacks->stack_b, NULL, stacks, "rb");
		}
		len_stack_a--;
	}
}

void	complex_sort(t_stacks *stacks)
{
	int		median_stack_a;
	int		len_stack_a;
	int		len_stack_b;
	t_stack	*min_nb;

	median_stack_a = get_median(stacks->stack_a);
	len_stack_a = ft_stacksize(stacks->stack_a);
	len_stack_b = 0;
	while (len_stack_a > 3 && len_stack_b < 3)
	{
		push(&stacks->stack_a, &stacks->stack_b, stacks, "pb");
		len_stack_a--;
		len_stack_b++;
	}
	move_to_stack_b(len_stack_a, median_stack_a, stacks);
	sort_3_numbers(stacks);
	len_stack_b = ft_stacksize(stacks->stack_b);
	while (len_stack_b-- > 0)
		push_to_stack_a(stacks);
	min_nb = find_min_nb(stacks->stack_a);
	index_numbers(stacks->stack_a);
	move_min_number_to_top(min_nb, stacks);
}
