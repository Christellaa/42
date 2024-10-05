/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:55:20 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/05 14:38:44 by cde-sous         ###   ########.fr       */
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

void	compare_bits(t_stacks *stacks, int bit_pos)
{
	int	stack_a_size;
	int	i;

	stack_a_size = ft_stacksize(stacks->stack_a);
	i = 0;
	while (i < stack_a_size)
	{
		if ((*(int *)stacks->stack_a->content & (1 << bit_pos)) == 0)
			pb(stacks);
		else
			ra(stacks);
		i++;
	}
}

void	radix_sort(t_stacks *stacks, t_stack *nb_max)
{
	int		bit_pos;
	int		bits_max;
	int		stack_b_size;

	bits_max = get_bits_max(nb_max);
	bit_pos = 0;
	while (bit_pos < bits_max)
	{
		compare_bits(stacks, bit_pos);
		stack_b_size = ft_stacksize(stacks->stack_b);
		while (stack_b_size--)
			pa(stacks);
		bit_pos++;
	}
}
