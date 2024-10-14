/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:38:01 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/14 12:47:36 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*start;

	if (stack)
	{
		start = stack;
		while (1)
		{
			tmp = stack;
			stack = stack->next;
			free(tmp);
			if (stack == start)
				break ;
		}
	}
}

void	free_group(char ***group)
{
	int	i;

	i = 0;
	if (group && *group)
	{
		while ((*group)[i])
		{
			free((*group)[i]);
			(*group)[i] = NULL;
			i++;
		}
		free((*group));
		*group = NULL;
	}
}

void	cleanup(t_stacks *stacks, char ***numbers, int exit_type)
{
	if (stacks)
	{
		free_stack(stacks->stack_a);
		free_stack(stacks->stack_b);
	}
	if (numbers)
		free_group(numbers);
	if (exit_type == 0)
	{
		// sorted
		write(1, OK, 3);
		exit(EXIT_SUCCESS);
	}
	else if (exit_type == 1)
	{
		// invalid args
		write(2, ERROR, 6);
		exit(EXIT_FAILURE);
	}
	else
	{
		// not sorted
		write(2, KO, 3);
		exit(EXIT_FAILURE);
	}
}
