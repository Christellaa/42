/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:05:11 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/23 11:00:28 by cde-sous         ###   ########.fr       */
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

// define error messages

typedef struct s_table
{
	int	nb_philo;
	int	time_death;
	int	time_eat;
	int	time_sleep;
	int	max_meals;
}		t_table;

// cleanup.c
void	ft_clean(t_table *table, int exit_type, char *msg);
// utils.c
int		ft_atoi(const char *nptr);
int		ft_strncmp(char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		print_error(const char *msg);

#endif