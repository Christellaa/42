/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:05:11 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/26 12:41:14 by cde-sous         ###   ########.fr       */
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
	int				dead;
	struct s_philo	*next;
}					t_philo;

typedef struct s_args
{
	int				nb_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				max_times_eat;
}					t_args;

// utils.c
int					ft_atoi(const char *nptr);
// list_utils.c
t_philo				*ft_new_philo(int id);
t_philo				*ft_list_last(t_philo *list);
void				ft_add_back_philo(t_philo **list, t_philo *new_philo);
// cleanup.c
void				ft_clean(t_philo *philo_list, int exit_type, char *msg);

#endif