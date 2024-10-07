/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:55:20 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/07 14:13:33 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_bits_max(t_stack *nb_max)
{
	int	bits_max;
	int	value;

	bits_max = 1;
	value = *(int *)nb_max->content;
	while (value)
	{
		value /= 2;
		if (value == 0)
			break ;
		bits_max++;
	}
	return (bits_max);
}

void	sort_stack_b(t_stacks *stacks, int stack_b_size, int bit_pos, \
		int bits_max)
{
	while (stack_b_size-- && bit_pos <= bits_max)
	{
		if (((stacks->stack_b->idx >> bit_pos) & 1) == 0)
			rb(stacks);
		else
			pa(stacks);
	}
}

void	compare_bits(t_stacks *stacks, int bit_pos, int stack_a_size)
{
	while (stack_a_size-- && !check_sorted(stacks->stack_a))
	{
		if (((stacks->stack_a->idx >> bit_pos) & 1) == 0)
			pb(stacks);
		else
			ra(stacks);
	}
}

void	radix_sort(t_stacks *stacks, t_stack *nb_max)
{
	int		bit_pos;
	int		bits_max;
	int		stack_a_size;
	int		stack_b_size;

	bits_max = get_bits_max(nb_max);
	bit_pos = 0;
	while (bit_pos <= bits_max && !check_sorted(stacks->stack_a))
	{
		stack_a_size = ft_stacksize(stacks->stack_a);
		compare_bits(stacks, bit_pos, stack_a_size);
		stack_b_size = ft_stacksize(stacks->stack_b);
		if (!check_inverse_sorted(stacks->stack_b))
			sort_stack_b(stacks, stack_b_size, bit_pos + 1, bits_max);
		bit_pos++;
	}
	stack_b_size = ft_stacksize(stacks->stack_b);
	while (stack_b_size--)
		pa(stacks);
	while (!check_sorted(stacks->stack_a))
		ra(stacks);
}
