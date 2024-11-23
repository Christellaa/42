/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:30:39 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/23 14:32:57 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->table->print_lock);
	if (status == FORK_1)
		printf("%d has taken fork 1\n", philo->id);
	if (status == FORK_2)
		printf("%d has taken fork 2\n", philo->id);
	if (status == EAT)
		printf("%d is eating\n", philo->id);
	if (status == SLEEP)
		printf("%d is sleeping\n", philo->id);
	if (status == THINK)
		printf("%d is thinking\n", philo->id);
	if (status == DEAD)
		printf("%d died\n", philo->id);
	pthread_mutex_unlock(&philo->table->print_lock);
}

void	*run_simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->fork_left);
	print_status(philo, FORK_1);
	pthread_mutex_lock(philo->fork_right);
	print_status(philo, FORK_2);
	print_status(philo, EAT);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
	return (NULL);
}
