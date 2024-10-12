/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:07:36 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/12 17:04:17 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	get_target(t_stacks *stacks)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;

	tmp_b = stacks->stack_b;
	while (tmp_b)
	{
		index_numbers(stacks->stack_a);
		index_numbers(stacks->stack_b);
		tmp_b->target = NULL;
		tmp_a = stacks->stack_a;
		while (tmp_a)
		{
			// ft_printf("tmp_b: %d (%d), tmp_a: %d (%d)\n", tmp_b->content,
			//	tmp_b->idx, tmp_a->content, tmp_a->idx);
			if (tmp_b->content < tmp_a->content && (tmp_b->target == NULL
					|| tmp_a->content < tmp_b->target->content))
				tmp_b->target = tmp_a;
			tmp_a = tmp_a->next;
			if (tmp_a == stacks->stack_a)
				break ;
		}
		if (tmp_b->target == NULL)
			tmp_b->target = find_min_nb(stacks->stack_a);
		tmp_b = tmp_b->next;
		if (tmp_b == stacks->stack_b)
			break ;
	}
}

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
	ft_printf("target of %d (%d): %d (%d)\n", cheapest->content, cheapest->idx,
		cheapest->target->content, cheapest->target->idx);
	while (cheapest->idx != 0 || cheapest->target->idx != 0)
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
			else if (cheapest->target->idx != 0
				&& cheapest->target->idx > median_a)
				rev_rotate(&stacks->stack_a, NULL, stacks, "rra");
			else if (cheapest->target->idx != 0
				&& cheapest->target->idx <= median_a)
				rotate(&stacks->stack_a, NULL, stacks, "ra");
		}
		index_numbers(stacks->stack_a);
		if (cheapest->idx == 0 || cheapest->target->idx == 0)
			break ;
	}
	push(&stacks->stack_b, &stacks->stack_a, stacks, "pa");
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
		get_target(stacks);
		median_stack_a = get_median(stacks->stack_a);
		median_stack_b = get_median(stacks->stack_b);
		index_numbers(stacks->stack_a);
		index_numbers(stacks->stack_b);
		get_min_moves(stacks, median_stack_a, median_stack_b);
	}
	cheapest = find_cheapest_number(stacks);
	push_cheapest_number(stacks, cheapest, median_stack_b, median_stack_a);
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
	sort_3_numbers(stacks);
	len_stack_b = ft_stacksize(stacks->stack_b);
	while (len_stack_b-- > 0)
		push_to_stack_a(stacks);
	min_nb = find_min_nb(stacks->stack_a);
	index_numbers(stacks->stack_a);
	median_stack_a = get_median(stacks->stack_a);
	while (min_nb->idx != 0)
	{
		if (min_nb->idx < median_stack_a)
			rotate(&stacks->stack_a, NULL, stacks, "ra");
		else
			rev_rotate(&stacks->stack_a, NULL, stacks, "rra");
		index_numbers(stacks->stack_a);
	}
}

/* 	t_stack *tmp = stacks->stack_a;
	while (tmp)
	{
		ft_printf("content: %d\n", tmp->content);
		tmp = tmp->next;
		if (tmp == stacks->stack_a)
			break ;
	}
 */

/*
	tmp_b = stacks->stack_b;
	while (tmp_b)
	{
		ft_printf("target of %d: %d", tmp_b->content, tmp_b->target->content);
		tmp_b = tmp_b->next;
		if (tmp_b == stacks->stack_b)
			break ;
	} */