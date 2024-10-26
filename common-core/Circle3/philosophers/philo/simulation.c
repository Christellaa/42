/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:01:02 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/26 16:08:16 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*actions(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// while not dead
	// lock mutex
	while (philo->dead == 0)
	{
		printf("ayo\n");
		pthread_mutex_lock(philo->lock);
		// eat
		printf("thread %d is eating\n", philo->id);
		philo->dead = 1;
		// unlock mutex
		pthread_mutex_unlock(philo->lock);
		// think
		// sleep
	}
	return (NULL);
}

void	run_simulation(t_philo **philo_list, t_args args)
{
	pthread_mutex_t lock;
	t_philo *philo;

	// create a mutex to lock forks
	// create one thread per philo
	philo = *philo_list;
	while (philo)
	{
		pthread_mutex_init(&lock, NULL);
		printf("creating thread %d\n", philo->id);
		philo->lock = &lock;
		pthread_create(&philo->thread_id, NULL, actions, philo);
		philo = philo->next;
	}
	// join threads in its process
	philo = *philo_list;
	while (philo)
	{
		printf("joining thread %d\n", philo->id);
		pthread_join(philo->thread_id, NULL);
		philo = philo->next;
	}
	// delete lock
	pthread_mutex_destroy(&lock);
	//(void)*philo_list;
	(void)args;
}