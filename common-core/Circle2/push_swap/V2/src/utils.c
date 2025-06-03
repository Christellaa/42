/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:23:52 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/13 20:34:47 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*new_content;

	new_content = malloc(sizeof(t_stack));
	if (!new_content)
		return (NULL);
	new_content->content = content;
	new_content->next = NULL;
	new_content->prev = NULL;
	new_content->idx = -1;
	new_content->target = NULL;
	return (new_content);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return ;
	if (*stack)
	{
		last = (*stack)->prev;
		last->next = new_node;
		new_node->prev = last;
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*stack = new_node;
	}
}

int	ft_stacksize(t_stack *stack)
{
	int		i;
	t_stack	*start;

	i = 0;
	start = stack;
	while (stack)
	{
		i++;
		stack = stack->next;
		if (stack == start)
			break ;
	}
	return (i);
}
