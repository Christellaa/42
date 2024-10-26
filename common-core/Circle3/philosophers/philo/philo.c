/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:14:20 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/26 12:44:27 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(int ac, char **av, t_args *args, t_philo **philo_list)
{
	int	i;

	i = 0;
	while (++i < ac)
		if (ft_atoi(av[i]) == 0 && av[i][0] != '0')
			return (0);
	args->nb_philo = ft_atoi(av[1]);
	args->time_death = ft_atoi(av[2]);
	args->time_eat = ft_atoi(av[3]);
	args->time_sleep = ft_atoi(av[4]);
	args->max_times_eat = -1;
	if (ac == 6)
		args->max_times_eat = ft_atoi(av[5]);
	i = 0;
	while (++i <= args->nb_philo)
		ft_add_back_philo(philo_list, ft_new_philo(i));
	if (!philo_list)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_args	args;
	t_philo	*philo_list;

	philo_list = NULL;
	if (ac != 5 && ac != 6)
		ft_clean(philo_list, 1, "Wrong number of arguments.");
	if (parse_args(ac, av, &args, &philo_list) == 0)
		ft_clean(philo_list, 1, "Arguments are not numbers or parsing error.");
	ft_clean(philo_list, 0, NULL);
}

/* // loop to see all philo
tmp = philo_list;
printf("nb of philo: %d\n", args->nb_philo);
while (tmp)
{
	printf("philo nb %d\n", tmp->id);
	tmp = tmp->next;
}
// loop to see all args
printf("\nargs\n");
printf("nb_philo: %d\ntime_death: %d\ntime_eat: \
	%d\ntime_sleep: %d\nmax_time_eat: %d\n",
		args->nb_philo,
		args->time_death,
		args->time_eat,
		args->time_sleep,
		args->max_times_eat); */