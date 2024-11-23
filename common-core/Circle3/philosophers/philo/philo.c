/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:43:05 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/23 12:53:20 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->forks)
		return (0);
	i = -1;
	while (++i < table->nb_philo)
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (destroy_forks(table));
	if (pthread_mutex_init(&table->print_lock, NULL) != 0)
		return (destroy_forks(table));
	if (pthread_mutex_init(&table->ready_all_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&table->print_lock);
		return (destroy_forks(table));
	}
	table->are_mutex_init = 1;
	return (1);
}

int	parse_args(int ac, char **av, t_table *args)
{
	int	i;

	i = 0;
	args->are_mutex_init = 0;
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

	table = malloc(sizeof(t_table));
	if (!table)
		ft_clean(table, 1, "Unable to allocate memory to table.");
	if (ac != 5 && ac != 6)
		ft_clean(table, 1,
			"Wrong number of arguments. It must be between 5 and 6 arguments.");
	if (parse_args(ac, av, table) == 0)
		ft_clean(table, 1, "Invalid arguments.\
			\nAll must be numeric and more than 0 (beside the 6th one).");
	if (init_mutexes(table) == 0)
		ft_clean(table, 1, "Unable to initialize mutexes.");
	ft_clean(table, 0, NULL);
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