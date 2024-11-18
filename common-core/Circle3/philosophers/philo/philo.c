/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:14:20 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/12 14:28:45 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_forks(t_philo *philo)
{
	/* if (philo->id == philo->table->nb_philo)
	{
		philo->fork_left = &philo->table->forks[philo->id - 1];
		philo->fork_right = &philo->table->forks[0];
	} */
	if (philo->id % 2)
	{
		philo->fork_left = &philo->table->forks[(philo->id)
			% philo->table->nb_philo];
		philo->fork_right = &philo->table->forks[philo->id - 1];
	}
	else
	{
		philo->fork_left = &philo->table->forks[philo->id - 1];
		philo->fork_right = &philo->table->forks[(philo->id)
			% philo->table->nb_philo];
	}
}

int	create_philo_list(t_philo **philo_list, t_table *table)
{
	int	i;

	*philo_list = malloc(sizeof(t_philo) * table->nb_philo);
	if (!*philo_list)
		return (0);
	i = 0;
	printf("nb philo: %d\n", table->nb_philo);
	while (i < table->nb_philo)
	{
		(*philo_list)[i].id = i + 1;
		printf("thread id: %d\n", (*philo_list)[i].id);
		(*philo_list)[i].times_eaten = 0;
		(*philo_list)[i].time_last_meal = -1;
		(*philo_list)[i].table = table;
		assign_forks(&(*philo_list)[i]);
		if (pthread_create(&(*philo_list)[i].thread_id, NULL, run_simulation,
				&(*philo_list)[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_mutexes(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->forks)
		return (0);
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&table->print_lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table->ready_philos, NULL) != 0)
		return (0);
	return (1);
}

int	parse_args(int ac, char **av, t_table *args)
{
	int	i;

	i = 0;
	while (++i < ac)
		if (ft_atoi(av[i]) == 0 && av[i][0] != '0')
			return (0);
	args->nb_philo = ft_atoi(av[1]);
	if (args->nb_philo < 1)
		return (0);
	args->time_death = ft_atoi(av[2]);
	args->time_eat = ft_atoi(av[3]);
	args->time_sleep = ft_atoi(av[4]);
	args->max_times_eat = -1;
	if (ac == 6)
		args->max_times_eat = ft_atoi(av[5]);
	args->start_time = 0;
	args->ready_philos_counter = 0;
	args->stop_simulation = 0;
	return (1);
}

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	*philo_list;

	table = malloc(sizeof(t_table));
	philo_list = NULL;
	if (ac != 5 && ac != 6)
		ft_clean(table, philo_list, 1, "Wrong number of arguments.");
	if (parse_args(ac, av, table) == 0)
		ft_clean(table, philo_list, 1,
			"Arguments are not numbers or parsing error or nb philo < 1.");
	if (init_mutexes(table) == 0)
		ft_clean(table, philo_list, 1, "Cannot initialize mutexes");
	if (create_philo_list(&philo_list, table) == 0)
		ft_clean(table, philo_list, 1, "Cannot create list of philosophers.");
	while (1)
	{
		pthread_mutex_lock(&table->ready_philos);
		if (table->ready_philos_counter == table->nb_philo)
		{
			table->start_time = get_time();
			pthread_mutex_unlock(&table->ready_philos);
			break ;
		}
		pthread_mutex_unlock(&table->ready_philos);
		usleep(100);
	}
	ft_clean(table, philo_list, 0, NULL);
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
