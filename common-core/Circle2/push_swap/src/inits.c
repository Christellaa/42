/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:02:59 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/15 16:04:52 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_struct(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_b = 0;
	stacks->count = 0;
	stacks->min_nb = 0;
	stacks->max_nb = 0;
	stacks->operations = ft_calloc(sizeof(char *), 1);
	stacks->operation_count = 0;
	stacks->is_double_operations = 0;
}

void	index_numbers(t_stack *stack)
{
	t_stack	*tmp;
	int		count;

	tmp = stack;
	count = -1;
	while (tmp)
	{
		tmp->idx = ++count;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
}

int	get_median(t_stack *stack)
{
	int	len;

	len = ft_stacksize(stack);
	return (len / 2);
}
