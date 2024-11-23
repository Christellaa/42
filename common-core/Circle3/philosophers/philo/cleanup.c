/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:59:13 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/23 11:05:23 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clean(t_table *table, int exit_type, char *msg)
{
	if (table)
		free(table);
	if (exit_type == 0)
		exit(EXIT_SUCCESS);
	else if (exit_type == 1)
	{
		if (msg)
			printf("%s\n", msg);
		exit(EXIT_FAILURE);
	}
}