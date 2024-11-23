/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:59:13 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/23 12:51:50 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_forks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
		pthread_mutex_destroy(&table->forks[i]);
	free(table->forks);
	return (0);
}

void	ft_clean(t_table *table, int exit_type, char *msg)
{
	if (msg)
		printf("%s\n", msg);
	if (table)
	{
		if (table->are_mutex_init == 1)
		{
			destroy_forks(table);
			pthread_mutex_destroy(&table->print_lock);
			pthread_mutex_destroy(&table->ready_all_lock);
		}
		free(table);
	}
	if (exit_type == 0)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}