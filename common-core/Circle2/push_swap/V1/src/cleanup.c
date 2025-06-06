/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:25:23 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/09 20:31:16 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	store_operation(t_stacks *stacks, char *operation)
{
	char	**tmp;

	tmp = ft_realloc(stacks->operations, \
	sizeof(char *) * stacks->operation_count, \
	sizeof(char *) * (stacks->operation_count + 2));
	if (!tmp)
		cleanup(stacks, NULL, 0);
	stacks->operations = tmp;
	stacks->operations[stacks->operation_count] = ft_strdup(operation);
	stacks->operation_count++;
	stacks->operations[stacks->operation_count] = NULL;
	stacks->is_double_operations = 0;
}

void	print_operations(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (!stacks->operations)
		return ;
	while (stacks->operations && i < stacks->operation_count)
	{
		ft_printf("%s\n", stacks->operations[i]);
		i++;
	}
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
			free(tmp->content);
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
	if (exit_type == 1)
	{
		print_operations(stacks);
		free_group(&(stacks->operations));
		exit(EXIT_SUCCESS);
	}
	else
	{
		free_group(&(stacks->operations));
		write(2, ERROR, 6);
		exit(EXIT_FAILURE);
	}
}
