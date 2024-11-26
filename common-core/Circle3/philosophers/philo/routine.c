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

int	only_one_philo(t_philo *philo)
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
	return (1);
}

int	philo_eat(t_philo *philo)
{
	if (only_one_philo(philo) == 0)
		return (0);
	pthread_mutex_lock(philo->fork_left);
	print_status(philo, FORK_1);
	pthread_mutex_lock(philo->fork_right);
	print_status(philo, FORK_2);
	print_status(philo, EAT);
	philo->last_meal_time = get_time_relative(philo->table);
	usleep(philo->table->time_eat);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
	return (1);
}

int	actions(t_philo *philo)
{
	if (philo->times_eaten == philo->table->max_meals)
		return (0);
	if (philo_eat(philo) == 0)
		return (0);
	if (philo->times_eaten == philo->table->max_meals)
		return (0);
	// sleep
	print_status(philo, SLEEP);
	usleep(philo->table->time_sleep);
	// think
	print_status(philo, THINK);
	return (1);
}

void	*run_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	check_all_ready(philo);
	if (philo->id % 2 == 0)
		usleep(philo->table->time_eat);
	while (1)
		if (actions(philo) == 0)
			break ;
	return (NULL);
}
