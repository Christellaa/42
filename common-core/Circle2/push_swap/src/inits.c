/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:02:59 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/02 19:07:08 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_struct(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_b = 0;
	stacks->count = 0;
	stacks->min = 0;
	stacks->max = 0;
	stacks->operations = ft_calloc(sizeof(char *), 1);
	stacks->operation_count = 1;
	stacks->is_double_operations = 0;
}

void	re_init_values(t_stacks *stacks)
{
	stacks->min = 0;
	stacks->max = 0;
}
