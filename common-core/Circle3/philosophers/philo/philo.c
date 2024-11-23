/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:43:05 by cde-sous          #+#    #+#             */
/*   Updated: 2024/11/23 10:32:51 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
init args inside struct table
if arg[i] != 5 and atoi(arg[i]) == 0, invalid arg
if arg[i] == 5 and atoi(arg[i]) == 0 and arg[i] != "0", invalid arg
*/
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
	t_table *table;

	table = malloc(sizeof(t_table));
	if (ac != 5 && ac != 6)
	{
		printf("Wrong nb of arguments.\n");
		return (1);
	}
	if (parse_args(ac, av, table) == 0)
	{
		printf("Arguments are not numbers OR parsing error OR nb philo < 1.\n");
		return (1);
	}
	printf("nb philo: %d\ntime death: %d\ntime eat: %d\ntime sleep: \
		%d\nmax meals: %d\n",
			table->nb_philo,
			table->time_death,
			table->time_eat,
			table->time_sleep,
			table->max_meals);
	return (0);
}