/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:55:12 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/12 17:00:04 by cde-sous         ###   ########.fr       */
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
		// ft_printf("tmp: %d, target: %d, mediana: %d, sizea: %d\n",
		//	tmp_b->content, tmp_a->content, median_a,
		//	ft_stacksize(stacks->stack_a));
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
