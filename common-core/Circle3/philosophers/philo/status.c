/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:17:47 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/26 14:01:10 by cde-sous         ###   ########.fr       */
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

int	check_death_status(t_table *table)
{
	pthread_mutex_lock(&table->is_dead_lock);
	if (table->is_dead == 1)
	{
		pthread_mutex_unlock(&table->is_dead_lock);
		return (0);
	}
	pthread_mutex_unlock(&table->is_dead_lock);
	return (1);
}

int	print_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->table->print_lock);
	if (check_death_status(philo->table) == 0)
	{
		pthread_mutex_unlock(&philo->table->print_lock);
		return (0);
	}
	if (status == FORK)
		printf("%ld %d has taken a fork\n", get_time_relative(philo->table),
			philo->id);
	else if (status == EAT)
		printf("%ld %d is eating\n", get_time_relative(philo->table),
			philo->id);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", get_time_relative(philo->table),
			philo->id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", get_time_relative(philo->table),
			philo->id);
	else if (status == DEAD)
		printf("%ld %d died\n", get_time_relative(philo->table), philo->id);
	pthread_mutex_unlock(&philo->table->print_lock);
	return (1);
}

int	check_if_dead(time_t current_time, t_table *table, t_philo **philo_list)
{
	int		i;
	time_t	last_meal;

	i = -1;
	while (++i < table->nb_philo)
	{
		if ((*philo_list)[table->nb_philo
			- 1].times_eaten == (*philo_list)->table->max_meals)
			return (0);
		if (check_death_status(table) == 0)
			return (0);
		pthread_mutex_lock(&table->start_lock);
		last_meal = (*philo_list)[i].last_meal_time;
		pthread_mutex_unlock(&table->start_lock);
		if ((current_time - last_meal) >= table->time_death)
		{
			print_status(&(*philo_list)[i], DEAD);
			pthread_mutex_lock(&table->is_dead_lock);
			table->is_dead = 1;
			pthread_mutex_unlock(&table->is_dead_lock);
			return (0);
		}
	}
	return (1);
}

void	*monitor_routine(void *arg)
{
	t_philo	**philo_list;
	t_table	*table;
	time_t	current_time;

	philo_list = (t_philo **)arg;
	table = (*philo_list)[0].table;
	check_all_ready(&(*philo_list)[0]);
	while (1)
	{
		current_time = get_time_relative(table);
		if (check_if_dead(current_time, table, philo_list) == 0)
			break ;
		usleep(10);
	}
	return (NULL);
}
