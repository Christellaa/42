/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:30:39 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/23 16:48:10 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		printf("%ld %d is eating\n", get_time() - philo->table->start_time,
			philo->id);
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

int	philo_eat(t_philo *philo)
{
	if (philo->table->nb_philo == 1)
	{
		pthread_mutex_lock(philo->fork_left);
		print_status(philo, FORK_1);
		usleep(philo->table->time_death);
		pthread_mutex_unlock(philo->fork_left);
		print_status(philo, DEAD);
		return (0);
	}
	pthread_mutex_lock(philo->fork_left);
	print_status(philo, FORK_1);
	pthread_mutex_lock(philo->fork_right);
	print_status(philo, FORK_2);
	print_status(philo, EAT);
	usleep(philo->table->time_eat);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
	return (1);
}

void	*run_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// wait for all philos before starting
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
	// make philo % 2 wait time_eat before starting
	if (philo->id % 2 == 0)
		usleep(philo->table->time_eat);
	// eat
	while (1)
	{
		if (philo->times_eaten == philo->table->max_meals)
			break ;
		if (philo_eat(philo) == 0)
			break ;
		if (philo->times_eaten == philo->table->max_meals)
			break ;
		// sleep
		print_status(philo, SLEEP);
		usleep(philo->table->time_sleep);
		// think
		print_status(philo, THINK);
	}
	return (NULL);
}

// 3. loop until death