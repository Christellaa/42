/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:23:52 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/09 16:34:14 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stacknew(void *content)
{
	t_stack	*new_content;

	new_content = malloc(sizeof(t_stack));
	if (!new_content)
		return (NULL);
	new_content->content = content;
	new_content->next = NULL;
	new_content->prev = NULL;
	return (new_content);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (*stack)
	{
		last = (*stack)->prev;
		last->next = new;
		new->prev = last;
		new->next = *stack;
		(*stack)->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
		*stack = new;
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
		stack = stack->next;
		if (stack == start)
			break ;
		i++;
	}
	return (i);
}
