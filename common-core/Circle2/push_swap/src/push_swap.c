/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:16:22 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/27 09:05:17 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	split_args(char **av, char ***numbers, int i)
{
	*numbers = ft_split(av[i], ' ');
	if (!*numbers)
		cleanup(NULL, NULL, *numbers);
	return (1);
}

int	create_node(t_list **stack, char **numbers, int j)
{
	int	*content;

	content = malloc(sizeof(int));
	if (!content)
		cleanup(*stack, NULL, numbers);
	*content = ft_atoi(numbers[j]);
	if (*content == 0 && numbers[j][0] != '0')
	{
		free(content);
		cleanup(*stack, NULL, numbers);
	}
	ft_lstadd_back(stack, ft_lstnew((void *)content));
	return (1);
}

void	put_args_in_stack_a(char **av, t_stacks *stacks, char **numbers)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (!split_args(av, &numbers, i))
			cleanup(stacks->stack_a, NULL, numbers);
		j = 0;
		while (numbers[j])
		{
			if (!create_node(&(stacks->stack_a), numbers, j))
				cleanup(stacks->stack_a, NULL, numbers);
			j++;
		}
		free_group(numbers);
		i++;
	}
}

/* void	print_all(t_stacks *stacks, char *function_name)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = stacks->stack_a;
	tmp2 = stacks->stack_b;
	ft_printf("\n%s\n", function_name);
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
} */

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		**numbers;

	if (ac > 1)
	{
		//init_stacks(stacks);
		stacks.stack_a = NULL;
		stacks.stack_b = NULL;
		numbers = NULL;
		put_args_in_stack_a(av, &stacks, numbers);
		algorithms(&stacks);
		cleanup(stacks.stack_a, stacks.stack_b, numbers);
	}
	return (0);
}
