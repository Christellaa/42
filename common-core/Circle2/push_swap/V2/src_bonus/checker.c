/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:46:40 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/16 10:34:25 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

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
			&& numbers[j][0] != '0'))
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
			cleanup(stacks, &numbers, 1);
		j = 0;
		while (numbers[j])
		{
			if (!create_node(&(stacks->stack_a), numbers, j))
				cleanup(stacks, &numbers, 1);
			j++;
		}
		free_group(&numbers);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*line;

	if (ac < 2)
		return (0);
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	put_args_in_stack_a(av, &stacks);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		check_valid_operation(line);
		apply_operation(&stacks, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (!check_sorted(stacks.stack_a) || stacks.stack_b)
		cleanup(&stacks, NULL, 2);
	cleanup(&stacks, NULL, 0);
}
