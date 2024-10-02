/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:25:23 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/02 19:39:50 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	store_operation(t_stacks *stacks, char *operation)
{
	char	**tmp;

	tmp = ft_realloc(stacks->operations, \
	sizeof(char *) * stacks->operation_count, \
	sizeof(char *) * stacks->operation_count + 1);
	if (!tmp)
		cleanup(stacks, NULL, 0);
	stacks->operations = tmp;
	stacks->operations[stacks->operation_count] = ft_strdup(operation);
	stacks->operation_count++;
	stacks->is_double_operations = 0;
}

void	print_operations(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->operations && i < stacks->operation_count)
	{
		ft_printf("%s\n", stacks->operations[i]);
		i++;
	}
}

void	free_stack(t_stacks *stacks)
{
	t_list	*tmp;

	if (stacks->stack_a)
	{
		while (stacks->stack_a)
		{
			tmp = stacks->stack_a;
			stacks->stack_a = stacks->stack_a->next;
			free(tmp->content);
			free(tmp);
		}
	}
	if (stacks->stack_b)
	{
		while (stacks->stack_b)
		{
			tmp = stacks->stack_b;
			stacks->stack_b = stacks->stack_b->next;
			free(tmp->content);
			free(tmp);
		}
	}
}

void	free_group(char **group)
{
	int	i;

	i = 0;
	while (group[i])
	{
		free(group[i]);
		group[i] = NULL;
		i++;
	}
	free(group);
	group = NULL;
}

void	cleanup(t_stacks *stacks, char **numbers, int exit_type)
{
	if (stacks)
		free_stack(stacks);
	if (numbers)
		free_group(numbers);
	if (stacks->operations)
		free_group(stacks->operations);
	if (exit_type == 1)
	{
		print_operations(stacks);
		exit(EXIT_SUCCESS);
	}
	else
		exit(EXIT_FAILURE);
}
