/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:02:59 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/09 22:00:59 by cde-sous         ###   ########.fr       */
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

t_stack	*index_numbers(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*compare;
	t_stack	*nb_max;
	int		prev_count;

	tmp = stack_a;
	nb_max = stack_a;
	while (tmp)
	{
		prev_count = 0;
		compare = stack_a;
		while (compare)
		{
			if (*(int *)tmp->content > *(int *)compare->content)
				prev_count++;
			compare = compare->next;
			if (compare == stack_a)
				break ;
		}
		tmp->idx = prev_count;
		if (tmp->idx > nb_max->idx)
			nb_max = tmp;
		tmp = tmp->next;
		if (tmp == stack_a)
			break ;
	}
	return (nb_max);
}
