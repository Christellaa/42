/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:55:20 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/05 11:29:26 by cde-sous         ###   ########.fr       */
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

void	radix_sort(t_stacks *stacks, t_stack *nb_max)
{
	int	bits_max;
	int	stack_a_size;
	int	i;

	ft_printf("nbmax: %d: %d\n", *(int *)nb_max->content, nb_max->idx);
	bits_max = get_bits_max(nb_max);
	ft_printf("bits_max: %d\n", bits_max);
	stack_a_size = ft_stacksize(stacks->stack_a);
	i = 0;
	while (i < stack_a_size)
	{
		ft_printf("stacka.content: %d\n", *(int *)stacks->stack_a->content);
		stacks->stack_a = stacks->stack_a->next;
		i++;
	}
	cleanup(stacks, NULL, 1);
}
