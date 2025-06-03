/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:20:52 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/13 18:56:36 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*find_min_nb(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min_nb;

	tmp = stack;
	min_nb = tmp;
	while (tmp)
	{
		if (tmp->content < min_nb->content)
			min_nb = tmp;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (min_nb);
}

void	get_target(t_stacks *stacks)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;

	tmp_b = stacks->stack_b;
	while (tmp_b)
	{
		tmp_b->target = NULL;
		tmp_a = stacks->stack_a;
		while (tmp_a)
		{
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

void	move_min_number_to_top(t_stack *min_nb, t_stacks *stacks)
{
	int	median_a;

	median_a = get_median(stacks->stack_a);
	while (min_nb->idx != 0)
	{
		if (min_nb->idx > median_a)
			rev_rotate(&stacks->stack_a, NULL, stacks, "rra");
		else
			rotate(&stacks->stack_a, NULL, stacks, "ra");
		index_numbers(stacks->stack_a);
	}
}
