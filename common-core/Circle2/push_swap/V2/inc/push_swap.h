/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:07:37 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/13 21:02:45 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>

# define ERROR "Error\n"

typedef struct s_stack
{
	int				content;
	int				idx;
	struct s_stack	*target;
	int				moves;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				size_b;
	int				count;
	int				min_nb;
	int				max_nb;
	char			**operations;
	int				operation_count;
	int				is_double_operations;
}					t_stacks;

// utils.c
t_stack				*ft_stacknew(int content);
void				ft_stackadd_back(t_stack **stack, t_stack *new_node);
int					ft_stacksize(t_stack *stack);
// inits.c
void				init_struct(t_stacks *stacks);
void				index_numbers(t_stack *stack);
int					get_median(t_stack *stack);
// cleanup.c
void				store_operation(t_stacks *stacks, char *operation);
void				print_operations(t_stacks *stacks);
void				free_stack(t_stack *stack);
void				free_group(char ***group);
void				cleanup(t_stacks *stacks, char ***numbers, int exit_type);
// operations.c
void				pop_head_stack1(t_stack **stack1, t_stack *tmp);
void				push(t_stack **stack1, t_stack **stack2, t_stacks *stacks,
						char *operation);
void				rotate(t_stack **stack1, t_stack **stack2, t_stacks *stacks,
						char *operation);
void				rev_rotate(t_stack **stack1, t_stack **stack2,
						t_stacks *stacks, char *operation);
void				swap(t_stack **stack1, t_stack **stack2, t_stacks *stacks,
						char *operation);
// algorithms.c
int					check_sorted(t_stack *stack_a);
void				sort_3_numbers(t_stacks *stacks);
void				algorithms(t_stacks *stacks);
// min_moves.c
void				determine_min_moves(int moves_b, int moves_a,
						t_stack *tmp_b);
int					calculate_moves(t_stack *stack, int median, int stack_size);
void				get_min_moves(t_stacks *stacks, int median_a, int median_b);
// complex_sort_utils.c
t_stack				*find_min_nb(t_stack *stack);
void				get_target(t_stacks *stacks);
void				move_min_number_to_top(t_stack *min_nb, t_stacks *stacks);
// complex_sort.c
t_stack				*find_cheapest_number(t_stacks *stacks);
void				rotate_cheapest_number(t_stacks *stacks, t_stack *cheapest,
						int median_b, int median_a);
void				push_to_stack_a(t_stacks *stacks);
void				move_to_stack_b(int len_stack_a, int median_stack_a,
						t_stacks *stacks);

void				complex_sort(t_stacks *stacks);

#endif
