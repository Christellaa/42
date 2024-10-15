/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:23:52 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/15 16:06:24 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

t_stack	*ft_stacknew(int content)
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

int	check_valid_operation(char *operation)
{
	if (ft_strncmp(operation, "pa\n", 4) == 0 || ft_strncmp(operation, "pb\n",
			4) == 0 || ft_strncmp(operation, "sa\n", 4) == 0
		|| ft_strncmp(operation, "sb\n", 4) == 0 || ft_strncmp(operation,
			"ss\n", 4) == 0 || ft_strncmp(operation, "ra\n", 4) == 0
		|| ft_strncmp(operation, "rb\n", 4) == 0 || ft_strncmp(operation,
			"rr\n", 4) == 0 || ft_strncmp(operation, "rra\n", 5) == 0
		|| ft_strncmp(operation, "rrb\n", 5) == 0 || ft_strncmp(operation,
			"rrr\n", 5) == 0)
		return (1);
	return (0);
}

void	apply_operation(t_stacks *stacks, char *operation)
{
	if (ft_strncmp(operation, "pa\n", 4) == 0)
		push(&stacks->stack_b, &stacks->stack_a);
	else if (ft_strncmp(operation, "pb\n", 4) == 0)
		push(&stacks->stack_a, &stacks->stack_b);
	else if (ft_strncmp(operation, "sa\n", 4) == 0)
		swap(&stacks->stack_a, NULL, stacks);
	else if (ft_strncmp(operation, "sb\n", 4) == 0)
		swap(&stacks->stack_b, NULL, stacks);
	else if (ft_strncmp(operation, "ss\n", 4) == 0)
		swap(&stacks->stack_a, &stacks->stack_b, stacks);
	else if (ft_strncmp(operation, "ra\n", 4) == 0)
		rotate(&stacks->stack_a, NULL, stacks);
	else if (ft_strncmp(operation, "rb\n", 4) == 0)
		rotate(&stacks->stack_b, NULL, stacks);
	else if (ft_strncmp(operation, "rr\n", 4) == 0)
		rotate(&stacks->stack_a, &stacks->stack_b, stacks);
	else if (ft_strncmp(operation, "rra\n", 5) == 0)
		rev_rotate(&stacks->stack_a, NULL, stacks);
	else if (ft_strncmp(operation, "rrb\n", 5) == 0)
		rev_rotate(&stacks->stack_b, NULL, stacks);
	else if (ft_strncmp(operation, "rrr\n", 5) == 0)
		rev_rotate(&stacks->stack_a, &stacks->stack_b, stacks);
}
