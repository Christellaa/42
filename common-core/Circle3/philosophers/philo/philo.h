/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:05:11 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/26 09:13:51 by cde-sous         ###   ########.fr       */
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
	pthread_t		thread_id;
	int				times_eaten;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	int				nb_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				max_meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	ready_philos_lock;
	int				ready_philos_counter;
	int				are_mutex_init;
	time_t			start_time;
	pthread_mutex_t	start_lock;
}					t_table;

typedef enum e_status
{
	FORK_1,
	FORK_2,
	EAT,
	SLEEP,
	THINK,
	DEAD
}					t_status;

// cleanup.c
int					destroy_forks(t_table *table);
void				ft_clean(t_table *table, t_philo *philo_list, int exit_type,
						char *msg);
// utils.c
int					ft_atoi(const char *nptr);
int					ft_strncmp(char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
time_t				get_time(void);
time_t				get_time_relative(t_table *table);
// routine.c
void				print_status(t_philo *philo, t_status status);
int					philo_eat(t_philo *philo);
void				*run_routine(void *arg);
// inits.c
void				assign_forks(t_philo *philo);
int					init_philos(t_philo **philo_list, t_table *table);
int					init_forks(t_table *table);
int					init_mutexes(t_table *table);

#endif