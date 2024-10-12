/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:02:22 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/12 13:59:55 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	sort_3_numbers(t_stacks *stacks)
{
	int	i;
	int	j;
	int	k;

	if (check_sorted(stacks->stack_a))
		return ;
	i = stacks->stack_a->content;
	j = stacks->stack_a->next->content;
	k = stacks->stack_a->next->next->content;
	if (i > j && j < k && i < k)
		swap(&stacks->stack_a, NULL, stacks, "sa");
	else if (i > j && j < k && i > k)
		rotate(&stacks->stack_a, NULL, stacks, "ra");
	else if (i < j && j > k && i > k)
		rev_rotate(&stacks->stack_a, NULL, stacks, "rra");
	else if (i > j && j > k && i > k)
	{
		rotate(&stacks->stack_a, NULL, stacks, "ra");
		swap(&stacks->stack_a, NULL, stacks, "sa");
	}
	else if (i < j && j > k && i < k)
	{
		rev_rotate(&stacks->stack_a, NULL, stacks, "rra");
		swap(&stacks->stack_a, NULL, stacks, "sa");
	}
}

void	algorithms(t_stacks *stacks)
{
	index_numbers(stacks->stack_a);
	if (check_sorted(stacks->stack_a))
		cleanup(stacks, NULL, 1);
	if (stacks->count == 2)
		swap(&stacks->stack_a, NULL, stacks, "sa");
	else if (stacks->count == 3)
		sort_3_numbers(stacks);
	else
		complex_sort(stacks);
}
