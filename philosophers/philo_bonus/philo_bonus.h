/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:16:13 by agenoves          #+#    #+#             */
/*   Updated: 2022/04/28 16:30:30 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_init
{
	int		num_philo;
	int		to_die;
	int		to_eat;
	int		to_sleep;
	int		n_toeat;
	int		is_dead;
	int		alleat;
	pid_t	*pid;
	long	timestart;
	sem_t	semfork;
}			t_init;

typedef struct s_philo
{
	long long	last_meal;
	t_init		*init_ph;
	int			fork;
	int			n_meals;
	int			ph_id;
}				t_philo;

/* Utils */
int			ft_atoi(const char *str);
/* Initialize */
t_philo		*ft_fill_philo(t_init *init);
int			ft_init_philo(t_init *init, char **argv);
/* Checks */
int			ft_check_for_chars(char *str);
int			ft_check_input(int ac, char **av);
int			ft_check_args(int argc, char **argv);

#endif