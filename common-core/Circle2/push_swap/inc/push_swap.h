/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:07:37 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/27 14:54:34 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>

# define ERROR "Error\n"
# define SMALL_THRESHOLD 50

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		count;
	int		range_min;
	int		range_max;
}	t_stacks;

// test.c
void	print_all(t_stacks *stacks, char *function_name);
void	ft_test(t_stacks *stacks);
// inits.c
void	init_struct(t_stacks *stacks);
// cleanup.c
void	free_stack(t_list *stack);
void	free_group(char **group);
void	cleanup(t_list *stack_a, t_list *stack_b, char **numbers, \
		int exit_type);
// push.c
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
// rotate.c
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
// swap.c
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
// algorithms.c
void	algorithms();

#endif