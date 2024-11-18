/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:07:17 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/12 17:43:04 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, t_status status)
{
	if (status == TAKE_FORK_1)
		printf("%ld %d has taken a fork 1\n", get_time()
			- philo->table->start_time, philo->id);
	else if (status == TAKE_FORK_2)
		printf("%ld %d has taken a fork 2\n", get_time()
			- philo->table->start_time, philo->id);
	else if (status == EAT)
		printf("%ld %d is eating\n", get_time() - philo->table->start_time,
			philo->id);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", get_time() - philo->table->start_time,
			philo->id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", get_time() - philo->table->start_time,
			philo->id);
	else if (status == MAX_MEAL)
		printf("%ld %d finished all meals\n", get_time()
			- philo->table->start_time, philo->id);
	else if (status == DEAD)
		printf("%ld %d died\n", get_time() - philo->table->start_time,
			philo->id);
	else if (status == DEBUG)
		printf("%ld %d stopped action because someone is dead\n", get_time()
			- philo->table->start_time, philo->id);
}

int	get_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->table->print_lock);
	is_dead(philo);
	if (philo->table->stop_simulation == 1)
	{
		// print_status(philo, DEBUG);
		pthread_mutex_unlock(&philo->table->print_lock);
		return (0);
	}
	philo->time_last_meal = get_time() - philo->table->start_time;
	printf("last meal: %ld\n", philo->time_last_meal);
	print_status(philo, status);
	pthread_mutex_unlock(&philo->table->print_lock);
	return (1);
}

void	destroy_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
}

void	join_threads(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
}

void	ft_clean(t_table *table, t_philo *philo_list, int exit_type, char *msg)
{
	if (table)
	{
		if (philo_list)
		{
			join_threads(philo_list, table);
			free(philo_list);
		}
		if (table->forks)
			destroy_forks(table);
		if (&table->print_lock)
			pthread_mutex_destroy(&table->print_lock);
		if (&table->ready_philos)
			pthread_mutex_destroy(&table->ready_philos);
		free(table);
	}
	if (exit_type == 0)
		exit(EXIT_SUCCESS);
	else if (exit_type == 1)
	{
		printf("%s\n", msg);
		exit(EXIT_FAILURE);
	}
}
