/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:07:37 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/02 19:42:13 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>

# define ERROR "Error\n"

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_b;
	int		count;
	int		min;
	int		max;
	char	**operations;
	int		operation_count;
	int		is_double_operations;
}	t_stacks;

// test.c
void	print_all(t_stacks *stacks);
void	ft_test(t_stacks *stacks);
// inits.c
void	init_struct(t_stacks *stacks);
void	re_init_values(t_stacks *stacks);
// cleanup.c
void	store_operation(t_stacks *stacks, char *operation);
void	print_operations(t_stacks *stacks);
void	free_stack(t_stacks *stacks);
void	free_group(char **group);
void	cleanup(t_stacks *stacks, char **numbers, int exit_type);
// push.c
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
// rotate.c
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
// reverse_rotate.c
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
// swap.c
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
// algorithms.c
int		check_sorted(t_stacks *stacks);
void	find_min_max(t_stacks *stacks);
void	algorithms(t_stacks *stacks);
// simple_sort.c
void	sort_3_numbers(t_stacks *stacks);
void	sort_4_to_5_numbers(t_stacks *stacks);
void	simple_sort(t_stacks *stacks);
// radix_sort.c

#endif