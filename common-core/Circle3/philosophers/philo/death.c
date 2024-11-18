/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:17:36 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/12 18:45:57 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(void)
{
	struct timeval	tv;
	time_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	is_dead(t_philo *philo)
{
	time_t	current_time;

	current_time = get_time() - philo->table->start_time;
	if (philo->time_last_meal > -1 && philo->table->stop_simulation == 0
		&& current_time >= (philo->table->time_death + philo->time_last_meal))
	{
		print_status(philo, DEAD);
		philo->table->stop_simulation = 1;
	}
}

int	dead_while_action(t_philo *philo, t_status action)
{
	time_t	stop_action;
	time_t	action_n;
	time_t	remaining_time;

	if (action == EAT)
		action_n = philo->table->time_eat;
	if (action == WAIT)
		action_n = 1000;
	if (philo->time_last_meal > -1
		&& philo->table->time_death >= philo->time_last_meal)
		remaining_time = philo->table->time_death - philo->time_last_meal;
	else if (philo->time_last_meal > -1
		&& philo->table->time_death < philo->time_last_meal)
		remaining_time = philo->time_last_meal - philo->table->time_death;
	else
		remaining_time = philo->table->time_death;
	printf("time death: %d, time last meal: %ld\n", philo->table->time_death,
		philo->time_last_meal);
	printf("remaining time: %ld\n", remaining_time);
	stop_action = (get_time() - philo->table->start_time) + action_n;
	printf("stop action: %ld\n", stop_action);
	while ((get_time() - philo->table->start_time) < stop_action)
	{
		usleep(10);
		pthread_mutex_lock(&philo->table->print_lock);
		is_dead(philo);
		if (philo->table->stop_simulation == 1)
		{
			// print_status(philo, DEBUG);
			pthread_mutex_unlock(&philo->table->print_lock);
			return (1);
		}
		pthread_mutex_unlock(&philo->table->print_lock);
	}
	return (0);
}
