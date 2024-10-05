/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:55:20 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/05 11:15:10 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	radix_sort(t_stacks *stacks, t_stack *nb_max)
{
	ft_printf("nbmax: %d: %d\n", *(int *)nb_max->content, nb_max->idx);
	cleanup(stacks, NULL, 1);
	//index_numbers(stacks);
}
