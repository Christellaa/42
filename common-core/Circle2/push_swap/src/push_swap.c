/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:16:22 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/18 16:19:37 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_duplicate(t_stack *stack, int content)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->content == content)
			return (0);
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (1);
}

int	split_args(char **av, char ***numbers, int i)
{
	*numbers = ft_split(av[i], ' ');
	if (!*numbers || !**numbers)
		return (0);
	return (1);
}

int	create_node(t_stack **stack, char **numbers, int j)
{
	int		content;
	t_stack	*new_node;

	content = ft_atoi(numbers[j]);
	if (!is_duplicate(*stack, content) || (content == 0
			&& !(ft_strncmp(numbers[j], "0", ft_strlen(numbers[j])) == 0
				|| ft_strncmp(numbers[j], "-0", ft_strlen(numbers[j])) == 0
				|| ft_strncmp(numbers[j], "+0", ft_strlen(numbers[j])) == 0)))
		return (0);
	new_node = ft_stacknew(content);
	if (!new_node)
		return (0);
	ft_stackadd_back(stack, new_node);
	return (1);
}

void	put_args_in_stack_a(char **av, t_stacks *stacks)
{
	int		i;
	int		j;
	char	**numbers;

	i = 1;
	while (av[i])
	{
		if (!split_args(av, &numbers, i))
			cleanup(stacks, &numbers, 0);
		j = 0;
		while (numbers[j])
		{
			if (!create_node(&(stacks->stack_a), numbers, j))
				cleanup(stacks, &numbers, 0);
			stacks->count++;
			j++;
		}
		free_group(&numbers);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac > 1)
	{
		init_struct(&stacks);
		put_args_in_stack_a(av, &stacks);
		algorithms(&stacks);
		cleanup(&stacks, NULL, 1);
	}
	return (0);
}
