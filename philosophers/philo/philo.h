/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:44:59 by agenoves          #+#    #+#             */
/*   Updated: 2022/04/11 15:01:27 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

/* Struct dei vari filosofi */
typedef struct s_philo
{
	int				ph_id;
	int				fork;
	int				n_meals;
	int				num_philo;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				n_toeat;
	int				is_dead;
	long long		last_meal;
	pthread_mutex_t	*ph_forks;
}				t_philo;

/* Utils */
int			ft_atoi(const char *str);
int			ft_check_args(int argc, char **argv);
long long	ft_get_time(void);
/* Start Initialization */
t_philo		*ft_fill_philo(int argc, char **argv);
t_philo		*ft_init_philo(int argc, char **argv);

#endif