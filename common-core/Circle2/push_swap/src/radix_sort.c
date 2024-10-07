/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:55:20 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/07 18:45:13 by cde-sous         ###   ########.fr       */
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
	if (stack_b_size <= 0 || bit_pos > bits_max || \
		check_sorted(stacks->stack_a))
		return ;
	if (((stacks->stack_b->idx >> bit_pos) & 1) == 0)
		rb(stacks);
	else
		pa(stacks);
	sort_stack_b(stacks, stack_b_size - 1, bit_pos, bits_max);
	if (check_sorted(stacks->stack_a))
	{
		stack_b_size = ft_stacksize(stacks->stack_b);
		while (stack_b_size--)
			pa(stacks);
	}
}

void	compare_bits(t_stacks *stacks, int bit_pos, int stack_a_size)
{
	if (stack_a_size <= 0 || check_sorted(stacks->stack_a))
		return ;
	if (((stacks->stack_a->idx >> bit_pos) & 1) != 0)
		ra(stacks);
	else
		pb(stacks);
	compare_bits(stacks, bit_pos, stack_a_size - 1);
}

void	recursive_radix_sort(t_stacks *stacks, int bit_pos, int bits_max)
{
	int	stack_a_size;
	int	stack_b_size;

	if (bit_pos > bits_max || check_sorted(stacks->stack_a))
		return ;
	stack_a_size = ft_stacksize(stacks->stack_a);
	compare_bits(stacks, bit_pos, stack_a_size);
	stack_b_size = ft_stacksize(stacks->stack_b);
	sort_stack_b(stacks, stack_b_size, bit_pos + 1, bits_max);
	recursive_radix_sort(stacks, bit_pos + 1, bits_max);
}

void	radix_sort(t_stacks *stacks, t_stack *nb_max)
{
	int		bits_max;
	int		stack_b_size;

	bits_max = get_bits_max(nb_max);
	recursive_radix_sort(stacks, 0, bits_max);
	stack_b_size = ft_stacksize(stacks->stack_b);
	while (stack_b_size--)
		pa(stacks);
}
