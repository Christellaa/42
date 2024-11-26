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

int	is_dead_in_action(t_philo *philo, t_status action)
{
	time_t	action_time;

	if (action == EAT || action == WAIT_TO_EAT)
		action_time = philo->table->time_eat;
	else if (action == SLEEP)
		action_time = philo->table->time_sleep;
	else if (action == WAIT_TO_DIE)
		action_time = philo->table->time_death + 1;
	while (get_time_relative(philo->table) < action_time)
	{
		if (check_death_status(philo->table) == 0)
			return (0);
		usleep(100);
	}
	return (1);
}

int	only_one_philo(t_philo *philo)
{
	if (philo->table->nb_philo == 1)
	{
		pthread_mutex_lock(philo->fork_left);
		if (print_status(philo, FORK_1) == 0)
		{
			pthread_mutex_unlock(philo->fork_left);
			return (0);
		}
		is_dead_in_action(philo, WAIT_TO_DIE);
		// it was: usleep(philo->table->time_death);
		pthread_mutex_unlock(philo->fork_left);
		// print_status(philo, DEAD);
		return (0);
	}
	return (1);
}

int	philo_eat(t_philo *philo)
{
	if (only_one_philo(philo) == 0)
		return (0);
	pthread_mutex_lock(philo->fork_left);
	if (print_status(philo, FORK_1) == 0)
	{
		pthread_mutex_unlock(philo->fork_left);
		return (0);
	}
	pthread_mutex_lock(philo->fork_right);
	if (print_status(philo, FORK_2) == 0)
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		return (0);
	}
	philo->last_meal_time = get_time_relative(philo->table);
	if (print_status(philo, EAT) == 0)
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		return (0);
	}
	if (is_dead_in_action(philo, EAT) == 0)
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		return (0);
	}
	// it was: usleep(philo->table->time_eat);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
	return (1);
}

int	actions(t_philo *philo)
{
	if (philo->times_eaten == philo->table->max_meals)
		return (0);
	if (check_death_status(philo->table) == 0)
		return (0);
	if (philo_eat(philo) == 0)
		return (0);
	if (philo->times_eaten == philo->table->max_meals)
		return (0);
	if (print_status(philo, SLEEP) == 0)
		return (0);
	if (is_dead_in_action(philo, SLEEP) == 0)
		return (0);
	// it was: usleep(philo->table->time_sleep);
	if (print_status(philo, THINK) == 0)
		return (0);
	return (1);
}

void	*run_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	check_all_ready(philo);
	if (philo->id % 2 == 0)
		if (is_dead_in_action(philo, WAIT_TO_EAT) == 0)
			return (NULL);
	// it was: usleep(philo->table->time_eat);
	while (1)
		if (actions(philo) == 0)
			break ;
	return (NULL);
}
