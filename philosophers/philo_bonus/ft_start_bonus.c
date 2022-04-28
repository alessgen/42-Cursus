/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:07:47 by agenoves          #+#    #+#             */
/*   Updated: 2022/04/28 16:52:43 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*ft_fill_philo(t_init *init)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * init->num_philo);
	while (i < init->num_philo)
	{
		philo[i].ph_id = i + 1;
		philo[i].last_meal = 0;
		philo[i].n_meals = 0;
		philo[i].fork = i;
		philo[i].init_ph = init;
		i++;
	}
	return (philo);
}

int	ft_init_philo(t_init *init, char **argv)
{
	init->num_philo = ft_atoi(argv[1]);
	init->to_die = ft_atoi(argv[2]);
	init->to_eat = ft_atoi(argv[3]);
	init->to_sleep = ft_atoi(argv[4]);
	init->pid = malloc(sizeof(pid_t) * init->num_philo);
	init->is_dead = 0;
	init->alleat = 0;
	if (argv[5])
	{
		init->n_toeat = ft_atoi(argv[5]);
		if (init->n_toeat <= 0)
			return (0);
	}
	else
		init->n_toeat = -1;
	return (1);
}

int	ft_check_args(int argc, char **argv)
{
	if (argc > 4 && argc <= 6)
	{
		if (ft_atoi(argv[1]) < 1)
			return (printf("Error: At least one phisolopher needed!\n"));
		if (ft_atoi(argv[2]) < 1)
			return (printf("Error: time_to_die must be at least 1 ms and\
not higher then Max int!\n"));
		if (ft_atoi(argv[3]) < 1)
			return (printf("Error: time_to_eat must be at least 1 ms and\
not higher then Max int!\n"));
		if (ft_atoi(argv[4]) < 1)
			return (printf("Error: time_to_sleep must be at least 1 ms and\
not higher then Max int!\n"));
		if (argc == 6 && ft_atoi(argv[5]) < 1)
			return (printf("Error: number_of_times_each_philosopher_must_eat \
must be at least 1!\n"));
	}
	else
		return (printf("Error: INVALID ARGUMENT! You need to compile with: \
number_of_philosophers, time_to_die, time_to_eat, time_to_sleep \
and optional number_of_times_each_philosopher_must_eat\n"));
	return (0);
}

int	ft_check_for_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_input(int ac, char **av)
{
	int	i;

	i = 1;
	while (av[i] && i < ac)
	{
		if (ft_check_for_chars(av[i]))
			return (printf("Error: check the input for wrong characters!\n"));
		i++;
	}
	if (ft_check_args(ac, av))
		return (1);
	return (0);
}
