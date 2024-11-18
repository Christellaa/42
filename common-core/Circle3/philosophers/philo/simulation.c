/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:01:02 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/12 18:43:29 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	first_wait(t_philo *philo)
{
	if (philo->table->nb_philo == 1)
	{
		pthread_mutex_lock(philo->fork_left);
		get_status(philo, TAKE_FORK_1);
		usleep(philo->table->time_death);
		philo->table->stop_simulation = 1;
		print_status(philo, DEAD);
		pthread_mutex_unlock(philo->fork_left);
		return (0);
	}
	if (philo->times_eaten == 0 && philo->id % 2 == 0)
		if (dead_while_action(philo, WAIT) == 1)
			return (0);
	return (1);
}

int	philo_eat(t_philo *philo)
{
	// if (philo->table->nb_philo == 1)
	// take fork1, wait until death time then die
	/* if (first_wait(philo) == 0)
		return (0); */
	pthread_mutex_lock(philo->fork_left);
	if (get_status(philo, TAKE_FORK_1) == 0)
	{
		pthread_mutex_unlock(philo->fork_left);
		return (0);
	}
	pthread_mutex_lock(philo->fork_right);
	if (get_status(philo, TAKE_FORK_2) == 0)
		return (unlock_mutex_forks(philo));
	if (get_status(philo, EAT) == 0)
		return (unlock_mutex_forks(philo));
	if (dead_while_action(philo, EAT) == 1)
		return (unlock_mutex_forks(philo));
	// usleep(philo->table->time_eat * 1000);
	philo->times_eaten++;
	if (philo->table->max_times_eat > 0
		&& philo->times_eaten == philo->table->max_times_eat)
		return (unlock_mutex_forks(philo));
	unlock_mutex_forks(philo);
	return (1);
}

void	*run_simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->table->ready_philos);
	philo->table->ready_philos_counter++;
	pthread_mutex_unlock(&philo->table->ready_philos);
	while (philo->table->start_time == 0)
		usleep(100);
	while (1)
	{
		if (philo_eat(philo) == 0)
			break ;
		// sleep
		if (get_status(philo, SLEEP) == 0)
			break ;
		usleep(philo->table->time_sleep * 1000);
		// think
		get_status(philo, THINK);
		/* philo->table->ready_philos_counter = 0;
		while (philo->table->ready_philos_counter != philo->table->nb_philo)
		{
			pthread_mutex_lock(&philo->table->ready_philos);
			philo->table->ready_philos_counter++;
			pthread_mutex_unlock(&philo->table->ready_philos);
		}
		pthread_mutex_lock(&philo->table->ready_philos);
		philo->table->time_death = philo->table->time_death
			+ philo->time_last_meal;
		pthread_mutex_unlock(&philo->table->ready_philos); */
	}
	return (NULL);
}

/*

1. one philo died when it was sleeping
2. 10ms (0.01s) between death and printing it
*/
