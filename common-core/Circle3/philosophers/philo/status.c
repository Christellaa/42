/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:17:47 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/26 09:30:42 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_all_ready(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->ready_philos_lock);
	philo->table->ready_philos_counter++;
	pthread_mutex_unlock(&philo->table->ready_philos_lock);
	pthread_mutex_lock(&philo->table->start_lock);
	while (philo->table->start_time == -1)
	{
		pthread_mutex_unlock(&philo->table->start_lock);
		usleep(100);
		pthread_mutex_lock(&philo->table->start_lock);
	}
	pthread_mutex_unlock(&philo->table->start_lock);
}

void	print_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->table->print_lock);
	if (status == FORK_1)
		printf("%ld %d has taken fork 1\n", get_time()
			- philo->table->start_time, philo->id);
	else if (status == FORK_2)
		printf("%ld %d has taken fork 2\n", get_time()
			- philo->table->start_time, philo->id);
	else if (status == EAT)
		printf("%ld || %ld %d is eating\n", philo->last_meal_time, get_time()
			- philo->table->start_time, philo->id);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", get_time() - philo->table->start_time,
			philo->id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", get_time() - philo->table->start_time,
			philo->id);
	else if (status == DEAD)
		printf("%ld %d died\n", get_time() - philo->table->start_time,
			philo->id);
	pthread_mutex_unlock(&philo->table->print_lock);
}
