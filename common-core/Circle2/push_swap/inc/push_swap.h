/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:07:37 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/10 16:00:49 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>

# define ERROR "Error\n"

typedef struct s_stack
{
	void			*content;
	int				idx;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_b;
	int		count;
	int		min_nb;
	int		max_nb;
	char	**operations;
	int		operation_count;
	int		is_double_operations;
}	t_stacks;

// utils.c
t_stack	*ft_stacknew(void *content);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int		ft_stacksize(t_stack *stack);
// inits.c
void	init_struct(t_stacks *stacks);
t_stack	*index_numbers(t_stack *stack_a);
// cleanup.c
void	store_operation(t_stacks *stacks, char *operation);
void	print_operations(t_stacks *stacks);
void	free_stack(t_stack *stack);
void	free_group(char ***group);
void	cleanup(t_stacks *stacks, char ***numbers, int exit_type);
// operations.c
void	pop_head_stack1(t_stack **stack1, t_stack *tmp);
void	push(t_stack **stack1, t_stack **stack2, t_stacks *stacks, \
			char *operation);
void	rotate(t_stack **stack1, t_stack **stack2, t_stacks *stacks, \
			char *operation);
void	rev_rotate(t_stack **stack1, t_stack **stack2, t_stacks *stacks, \
				char *operation);
void	swap(t_stack **stack1, t_stack **stack2, t_stacks *stacks, \
			char *operation);
// algorithms.c
int		check_sorted(t_stack *stack_a);
void	find_min_max(t_stacks *stacks);
void	algorithms(t_stacks *stacks);
// simple_sort.c
void	sort_3_numbers(t_stacks *stacks);
int		get_pos_idx(t_stack *stack_a, int idx);
void	sort_4_to_5_numbers(t_stacks *stacks);
void	simple_sort(t_stacks *stacks);
// radix_sort.c
void	radix_sort(t_stacks *stacks, t_stack *nb_max);

#endif