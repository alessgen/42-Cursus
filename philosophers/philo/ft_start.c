/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:40:30 by agenoves          #+#    #+#             */
/*   Updated: 2022/04/12 18:42:35 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_init_philo(int argc, char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	philo->num_philo = ft_atoi(argv[1]);
	philo->to_die = ft_atoi(argv[2]);
	philo->to_eat = ft_atoi(argv[3]);
	philo->to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->n_toeat = ft_atoi(argv[5]);
	philo->is_dead = 0;
	philo->ph_forks = malloc(sizeof(pthread_mutex_t) * philo->num_philo);
	return (philo);
}

t_philo	*ft_fill_philo(int argc, char **argv)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = NULL;
	philo = ft_init_philo(argc, argv);
	while (i < philo->num_philo)
	{
		philo[i].ph_id = i + 1;
		philo[i].to_die = philo->to_die;
		philo[i].to_eat = philo->to_eat;
		philo[i].to_sleep = philo->to_sleep;
		philo[i].last_meal = ft_get_time();
		philo[i].fork = 1;
		philo[i].n_meals = 0;
		pthread_mutex_init(&philo->ph_forks[i], NULL);
		i++;
	}
	return (philo);
}
