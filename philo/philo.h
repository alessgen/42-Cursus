/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:44:59 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/30 18:30:45 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

/* Struct */
// Status contiene 1 se é vivo, 0 se é morto
typedef struct s_ph
{
	int			num_philo;
	int			to_die;
	int			to_eat;
	int			to_sleep;
	int			n_toeat;
	int			status;
}				t_ph;

/* List */
typedef struct s_list
{
	int				fork;
	struct s_list	*next;
}			t_list;

/* Utils */
int	ft_atoi(const char *str);
int	ft_check_args(int argc, char **argv);

#endif