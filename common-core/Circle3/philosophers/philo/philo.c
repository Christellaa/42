/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:43:05 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/23 14:03:34 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(int ac, char **av, t_table *args)
{
	int	i;

	i = 0;
	while (++i < ac)
		if ((i != 5 && ft_atoi(av[i]) == 0) || (i == 5 && ft_atoi(av[i]) == 0
				&& ft_strncmp(av[i], "0", ft_strlen(av[i])) != 0))
			return (0);
	args->nb_philo = ft_atoi(av[1]);
	args->time_death = ft_atoi(av[2]);
	args->time_eat = ft_atoi(av[3]);
	args->time_sleep = ft_atoi(av[4]);
	args->max_meals = -1;
	if (ac == 6)
		args->max_meals = ft_atoi(av[5]);
	return (1);
}

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	*philo_list;

	table = malloc(sizeof(t_table));
	philo_list = NULL;
	if (!table)
		ft_clean(table, philo_list, 1, "Unable to allocate memory to table.");
	table->are_mutex_init = 0;
	if (ac != 5 && ac != 6)
		ft_clean(table, philo_list, 1,
			"Wrong number of arguments.\nIt must be between 5 and 6 arguments.");
	if (parse_args(ac, av, table) == 0)
		ft_clean(table, philo_list, 1, "Invalid arguments.\
			\nAll must be numeric and more than 0 (beside the 6th one).");
	if (init_mutexes(table) == 0)
		ft_clean(table, philo_list, 1, "Unable to initialize mutexes.");
	if (init_philos(&philo_list, table) == 0)
		ft_clean(table, philo_list, 1, "Unable to initialize philosophers.");
	ft_clean(table, philo_list, 0, NULL);
}

/* print parsed args:

	printf("nb philo: %d\ntime death: %d\ntime eat: %d\ntime sleep: \
		%d\nmax meals: %d\n",
			table->nb_philo,
			table->time_death,
			table->time_eat,
			table->time_sleep,
			table->max_meals);
*/