/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:15:55 by agenoves          #+#    #+#             */
/*   Updated: 2022/04/28 16:36:04 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Fork system call is used for creating a new process, which is called child
process, which runs concurrently with the process that makes the fork() call 
(parent process). After a new child process is created, both processes will 
execute the next instruction following the fork() system call. A child process
uses the same pc(program counter), same CPU registers, same open files which
use in the parent process.
It takes no parameters and returns an integer value. Below are different values
returned by fork().
Negative Value: creation of a child process was unsuccessful.
Zero: Returned to the newly created child process.
Positive value: Returned to parent or caller. The value contains process ID
of newly created child process */

#include "philo_bonus.h"

int	ft_dinner(t_philo *philo)
{
	
}

int	ft_create_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i++ < philo->init_ph->num_philo)
	{
		philo->init_ph->pid[i] = fork();
		if (philo->init_ph->pid[i] < 0)
			printf("Fork Error\n");
		if (philo->init_ph->pid[i] != 0)
		{
			printf("Parent\n");
			printf("Pid: %d\n", philo->init_ph->pid[i]);
		}
		else
		{
			ft_dinner(philo);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_init	init;
	t_philo	*philo;
	int		i;

	i = 0;
	if (ft_check_input(argc, argv) != 0)
		return (1);
	if (!ft_init_philo(&init, argv))
		return (0);
	philo = ft_fill_philo(&init);
	ft_create_process(philo);
	return (0);
}
