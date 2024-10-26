/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:07:17 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/26 15:56:41 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_list(t_philo *philo_list)
{
	t_philo	*philo;

	while (philo_list)
	{
		philo = philo_list;
		philo_list = philo_list->next;
		free(philo);
	}
}

void	ft_clean(t_philo *philo_list, int exit_type, char *msg)
{
	if (philo_list)
		clean_list(philo_list);
	if (exit_type == 0)
		exit(EXIT_SUCCESS);
	else if (exit_type == 1)
	{
		printf("%s\n", msg);
		exit(EXIT_FAILURE);
	}
}