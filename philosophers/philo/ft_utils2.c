#include "philo.h"

void ft_smart_action(long long time, t_philo *philo)
{
	long long past;

	past = ft_get_time();
	while (!check_is_died(philo))
	{
		if (ft_get_time() - past >= time)
			break ;
		usleep(100);
	}
	return ;
}

int check_is_died(t_philo *philo)
{
	int a;
	pthread_mutex_lock(&philo->init_ph->death);
	a = philo->init_ph->is_dead;
	pthread_mutex_unlock(&philo->init_ph->death);
	return (a);
}

int	check_all_eat(t_philo *philo)
{
	int	c;

	pthread_mutex_lock(&philo->init_ph->allate);
	c = philo->init_ph->alleat;
	pthread_mutex_unlock(&philo->init_ph->allate);
	return (c);
}

int	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->init_ph->ph_forks[philo->lfork]);
	ft_printing(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->init_ph->ph_forks[philo->lfork]);
	usleep(philo->init_ph->to_die * 1000);
	ft_printing(philo, "died");
	return (1);
}