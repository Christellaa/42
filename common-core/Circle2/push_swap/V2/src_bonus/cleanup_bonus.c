/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:38:01 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/15 16:06:32 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

int	check_sorted(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
		if (tmp == stack_a || tmp->next == stack_a)
			break ;
	}
	if (tmp->content < stack_a->content)
		return (0);
	return (1);
}

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
		write(1, OK, 3);
		exit(EXIT_SUCCESS);
	}
	else if (exit_type == 1)
	{
		write(2, ERROR, 6);
		exit(EXIT_FAILURE);
	}
	else
	{
		write(2, KO, 3);
		exit(EXIT_FAILURE);
	}
}
