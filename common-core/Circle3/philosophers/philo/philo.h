/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:05:11 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/23 12:51:59 by cde-sous         ###   ########.fr       */
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

typedef struct s_table
{
	int				nb_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				max_meals;
	pthread_mutex_t *forks; // array of forks (1 for each philo)
	pthread_mutex_t	print_lock;
	pthread_mutex_t	ready_all_lock;
	int				are_mutex_init;
}					t_table;

// cleanup.c
int					destroy_forks(t_table *table);
void				ft_clean(t_table *table, int exit_type, char *msg);
// utils.c
int					ft_atoi(const char *nptr);
int					ft_strncmp(char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
int					print_error(const char *msg);

#endif