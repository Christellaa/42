/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:05:11 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/12 15:48:17 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				times_eaten;
	time_t			time_last_meal;
	pthread_t		thread_id;
	pthread_mutex_t *fork_left;  // points to forks of t_table
	pthread_mutex_t *fork_right; // points to forks of t_table
	struct s_table *table;       // to have access to shared data: nb philo,
									//	all times and stop sim
}					t_philo;

typedef struct s_table
{
	int				nb_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				max_times_eat;
	pthread_mutex_t *forks;     // array keeping all mutexes;
								// each philo can access the appropriate fork
								// pointers (fork left and fork right) during setup
	pthread_mutex_t print_lock; // sync output so threads dont garble each other
	int stop_simulation;        // shared flag stopping simulation when a
								// condition is met (philo died)
	pthread_mutex_t	ready_philos;
	int				ready_philos_counter;
	time_t			start_time;
}					t_table;

typedef enum e_status
{
	TAKE_FORK_1,
	TAKE_FORK_2,
	EAT,
	SLEEP,
	THINK,
	MAX_MEAL, // to delete, for debug
	DEAD,
	WAIT,
	DEBUG // to delete, for debug
}					t_status;

// utils.c
int					ft_atoi(const char *nptr);
int					unlock_mutex_forks(t_philo *philo);
// death.c
time_t				get_time(void);
void				is_dead(t_philo *philo);
int					dead_while_action(t_philo *philo, t_status action);
// cleanup.c
void				print_status(t_philo *philo, t_status status);
int					get_status(t_philo *philo, t_status status);
void				ft_clean(t_table *table, t_philo *philo_list, int exit_type,
						char *msg);
// simulation.c
void				*run_simulation(void *arg);

#endif
