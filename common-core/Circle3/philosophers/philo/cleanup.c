/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:59:13 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/25 16:28:45 by cde-sous         ###   ########.fr       */
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

void	join_threads(t_philo *philo, t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
		pthread_join(philo[i].thread_id, NULL);
}

void	ft_clean(t_table *table, t_philo *philo_list, int exit_type, char *msg)
{
	if (msg)
		printf("%s\n", msg);
	if (table)
	{
		if (philo_list)
		{
			pthread_join(table->monitor_thread, NULL);
			join_threads(philo_list, table);
			free(philo_list);
		}
		if (table->are_mutex_init == 1)
		{
			destroy_forks(table);
			pthread_mutex_destroy(&table->print_lock);
			pthread_mutex_destroy(&table->ready_philos_lock);
		}
		free(table);
	}
	if (exit_type == 0)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
