/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:55:20 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/05 16:09:50 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_mostly_sorted(t_stack *stack_a, int stack_a_size)
{
	t_stack	*tmp;
	int		sorted_count;
	int		current_idx;
	int		ratio;

	tmp = stack_a;
	sorted_count = 0;
	current_idx = 0;
	while (tmp)
	{
		if (current_idx == tmp->idx)
			sorted_count++;
		tmp = tmp->next;
		current_idx++;
	}
	ratio = (sorted_count * 100) / stack_a_size;
	if (ratio >= 70)
	{
		//ft_printf("insertion sort");
		return (1);
	}
	return (0);
}

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

int	check_next_numbers_bit(t_stack *stack_a, int bit_pos)
{
	while ((*(int *)stack_a->content & (1 << bit_pos)) == 1)
	{
		stack_a = stack_a->next;
		if (!stack_a)
			return (0);
	}
	while ((*(int *)stack_a->content & (1 << bit_pos)) == 0)
	{
		stack_a = stack_a->next;
		if (!stack_a || !stack_a->next->next)
			return (0);
	}
	return (1);
}

void	compare_bits(t_stacks *stacks, int bit_pos, int stack_a_size)
{
	int	i;
	int	stack_b_size;

	i = 0;
	while (i < stack_a_size \
		&& check_next_numbers_bit(stacks->stack_a, bit_pos))
	{
		if ((*(int *)stacks->stack_a->content & (1 << bit_pos)) == 0)
			pb(stacks);
		else
			ra(stacks);
		i++;
	}
	stack_b_size = ft_stacksize(stacks->stack_b);
	while (stack_b_size--)
		pa(stacks);
}

void	radix_sort(t_stacks *stacks, t_stack *nb_max)
{
	int		bit_pos;
	int		bits_max;
	int		stack_a_size;

	stack_a_size = ft_stacksize(stacks->stack_a);
	bits_max = get_bits_max(nb_max);
	bit_pos = 0;
	while (bit_pos < bits_max)
	{
		if (check_sorted(stacks))
			break ;
		compare_bits(stacks, bit_pos, stack_a_size);
		is_mostly_sorted(stacks->stack_a, stack_a_size);
			//insertion_sort(stacks);
		bit_pos++;
	}
}
