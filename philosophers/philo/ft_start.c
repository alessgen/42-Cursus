/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:40:30 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/31 17:35:49 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_fill_philo(int argc, char **argv)
{
	int			i;
	t_init		*init;
	t_philo		*philo;

	i = 0;
	init = ft_init_data(argc, argv);
	philo = malloc(sizeof(t_philo) * init->num_philo);
	while (i < init->num_philo)
	{
		philo[i].ph_id = i;
		philo[i].last_meal = ft_get_time();
		philo[i].fork = 1;
		philo[i].n_meals = 0;
		pthread_mutex_init(&init->ph_forks[i], NULL);
		i++;
	}
	return (philo);
}
