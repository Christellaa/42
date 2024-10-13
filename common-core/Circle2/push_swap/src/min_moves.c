/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:55:12 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/13 17:21:06 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	determine_min_moves(int moves_b, int moves_a, t_stack *tmp_b)
{
	if (moves_b > moves_a)
		tmp_b->moves = moves_b;
	else
		tmp_b->moves = moves_a;
}

int	calculate_moves(t_stack *stack, int median, int stack_size)
{
	if (stack->idx <= median)
		return (stack->idx);
	return (stack_size - stack->idx);
}

void	get_min_moves(t_stacks *stacks, int median_a, int median_b)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	int		moves_b;
	int		moves_a;

	tmp_b = stacks->stack_b;
	while (tmp_b)
	{
		tmp_b->moves = 0;
		moves_b = 0;
		moves_a = 0;
		tmp_a = tmp_b->target;
		moves_b = calculate_moves(tmp_b, median_b,
				ft_stacksize(stacks->stack_b));
		moves_a = calculate_moves(tmp_a, median_a,
				ft_stacksize(stacks->stack_a));
		if ((tmp_b->idx < median_b && tmp_a->idx < median_a)
			|| (tmp_b->idx > median_b && tmp_a->idx > median_a))
			determine_min_moves(moves_b, moves_a, tmp_b);
		else
			tmp_b->moves = moves_b + moves_a;
		tmp_b = tmp_b->next;
		if (tmp_b == stacks->stack_b)
			break ;
	}
}
