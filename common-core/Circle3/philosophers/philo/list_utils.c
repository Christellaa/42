/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:13:49 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/26 12:31:55 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_new_philo(int id)
{
	t_philo	*new_philo;

	new_philo = malloc(sizeof(t_philo));
	if (!new_philo)
		return (NULL);
	new_philo->id = id;
	new_philo->dead = 0;
	new_philo->times_eaten = 0;
	new_philo->next = NULL;
	return (new_philo);
}

t_philo	*ft_list_last(t_philo *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void	ft_add_back_philo(t_philo **list, t_philo *new_philo)
{
	t_philo *last;

	if (!list || !new_philo)
		return ;
	if (*list)
	{
		last = ft_list_last(*list);
		last->next = new_philo;
	}
	else
		*list = new_philo;
}