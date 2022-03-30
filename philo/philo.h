/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:44:59 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/30 19:49:56 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

/* Struct dell'inizializzazione */
// is_dead = 0 (vivo) - is_dead = 1 (morto).
typedef struct s_ph
{
	int				num_philo;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				n_toeat;
	int				is_dead;
	pthread_mutex_t	*ph_mutex;
}				t_ph;

/* Struct dei vari filosofi */
typedef struct s_philo
{
	int			ph_id;
	int			fork;
	long long	last_meal;
	int			n_meals;
}				t_philo;

/* Utils */
int			ft_atoi(const char *str);
int			ft_check_args(int argc, char **argv);
long long	ft_get_time(void);

#endif