/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:43:05 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/26 09:25:34 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ready_all_philos(t_table *table)
{
	while (1)
	{
		pthread_mutex_lock(&table->ready_philos_lock);
		if (table->ready_philos_counter == table->nb_philo)
		{
			pthread_mutex_lock(&table->start_lock);
			table->start_time = get_time();
			pthread_mutex_unlock(&table->start_lock);
			pthread_mutex_unlock(&table->ready_philos_lock);
			break ;
		}
		pthread_mutex_unlock(&table->ready_philos_lock);
		usleep(100);
	}
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
	args->ready_philos_counter = 0;
	args->start_time = -1;
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
	ready_all_philos(table);
	ft_clean(table, philo_list, 0, NULL);
}

/* print all philos:

	int		i = 0;
	printf("Printing all philosophers:\n");
	for (i = 0; i < philo_list->table->nb_philo; i++)
	{
		printf("Philosopher %d:\n", philo_list[i].id);
		printf("  ID: %d\n", philo_list[i].id);
		printf("  Times eaten: %d\n", philo_list[i].times_eaten);
		printf("  Last meal time: %ld\n", philo_list[i].last_meal_time);
		printf("  Table: %p\n", philo_list[i].table);
		// If you want to print more info about the forks or threads:
		printf("  Thread ID: %ld\n", philo_list[i].thread_id);
	}
*/

/* print parsed args:

	printf("nb philo: %d\ntime death: %d\ntime eat: %d\ntime sleep: \
		%d\nmax meals: %d\n",
			table->nb_philo,
			table->time_death,
			table->time_eat,
			table->time_sleep,
			table->max_meals);
*/