/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:53:28 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/01 13:35:01 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_all(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = stacks->stack_a;
	tmp2 = stacks->stack_b;
	//ft_printf("\n%s\n", function_name);
	ft_printf("stack_a:\n");
	while (tmp)
	{
		if (tmp->content)
			ft_printf("%d ", *(int *)(tmp->content));
		else
			ft_printf("NULL ");
		tmp = tmp->next;
	}
	ft_printf("\nstack_b:\n");
	while (tmp2)
	{
		if (tmp2->content)
			ft_printf("%d ", *(int *)(tmp2->content));
		else
			ft_printf("NULL ");
		tmp2 = tmp2->next;
	}
}

void	ft_test(t_stacks *stacks)
{
	pb(stacks);
	//print_all(stacks, "pa");
	//ft_printf("\ncount: %d\n", stacks->count);
	//ft_printf("range_min: %d\nrange_max: %d\n", stacks->range_min, stacks->range_max);
}
