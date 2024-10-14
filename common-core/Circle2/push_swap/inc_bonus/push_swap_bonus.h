/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:07:37 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/14 14:07:22 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <stddef.h>

# define ERROR "Error\n"
# define OK "OK\n"
# define KO "KO\n"

typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_stacks;

// utils_bonus.c
t_stack				*ft_stacknew(int content);
void				ft_stackadd_back(t_stack **stack, t_stack *new_node);
int					ft_stacksize(t_stack *stack);
int					check_sorted(t_stack *stack_a);
int					check_valid_operation(char *operation);
void				apply_operation(t_stacks *stacks, char *operation);
// inits_bonus.c
void				init_struct(t_stacks *stacks);
// cleanup_bonus.c
void				free_stack(t_stack *stack);
void				free_group(char ***group);
void				cleanup(t_stacks *stacks, char ***numbers, int exit_type);
// operations_bonus.c
void				pop_head_stack1(t_stack **stack1, t_stack *tmp);
void				push(t_stack **stack1, t_stack **stack2);
void				rotate(t_stack **stack1, t_stack **stack2,
						t_stacks *stacks);
void				rev_rotate(t_stack **stack1, t_stack **stack2,
						t_stacks *stacks);
void				swap(t_stack **stack1, t_stack **stack2, t_stacks *stacks);

#endif
