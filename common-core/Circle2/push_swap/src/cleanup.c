/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:25:23 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/26 13:43:03 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp->content);
		free(tmp);
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

void	cleanup(t_list *stack_a, t_list *stack_b, char **numbers)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (numbers)
		free_group(numbers);
	exit(EXIT_FAILURE);
}
