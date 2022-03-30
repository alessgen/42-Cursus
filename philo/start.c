/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:40:30 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/30 19:50:01 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	ft_fill_philo(t_ph *init)
{
	int			i;
	t_philo		*philo;

	i = -1;
	philo = malloc(sizeof(t_philo) * init->num_philo);
	while (++i < init->num_philo)
	{
		philo[i].ph_id = i + 1;
		philo[i].last_meal = ft_get_time();
		philo[i].n_meals = 0;
	}
}
