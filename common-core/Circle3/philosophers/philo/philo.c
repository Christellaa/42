/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:43:05 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/23 13:51:21 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		philo->fork_left = &philo->table->forks[philo->id
			% philo->table->nb_philo];
		philo->fork_right = &philo->table->forks[philo->id - 1];
	}
	else
	{
		philo->fork_left = &philo->table->forks[philo->id - 1];
		philo->fork_right = &philo->table->forks[philo->id
			% philo->table->nb_philo];
	}
}

int	init_philos(t_philo **philo_list, t_table *table)
{
	int	i;

	*philo_list = malloc(sizeof(t_philo) * table->nb_philo);
	if (!*philo_list)
		return (0);
	i = -1;
	while (++i < table->nb_philo)
	{
		(*philo_list)[i].id = i + 1;
		(*philo_list)[i].table = table;
		assign_forks(&(*philo_list)[i]);
		if (pthread_create(&(*philo_list)[i].thread_id, NULL, run_simulation,
				&(*philo_list)[i]) != 0)
			return (0);
	}
	return (1);
}

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