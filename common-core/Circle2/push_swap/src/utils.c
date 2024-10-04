/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:23:52 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/04 10:27:37 by cde-sous         ###   ########.fr       */
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
	return (new_content);
}

t_stack	*last_seen_stack(t_stack *stack, t_stack *last)
{
	if (!stack)
		return (last);
	return (last_seen_stack(stack->next, stack));
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	return (last_seen_stack(stack->next, stack));
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (*stack)
	{
		last = ft_stacklast(*stack);
		last->next = new;
	}
	else
		*stack = new;
}
