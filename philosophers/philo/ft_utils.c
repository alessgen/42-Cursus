/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:34:51 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/31 15:27:17 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	tv;
	long long		time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec) * 1000 + (tv.tv_sec) / 1000;
	return (time_in_ms);
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
must be at least 1 ms\n"));
	}
	else
		return (printf("Error: INVALID ARGUMENT! You need to compile with: \
number_of_philosophers, time_to_die, time_to_eat, time_to_sleep \
and optional number_of_times_each_philosopher_must_eat\n"));
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10;
		result = result + (*str - 48);
		str++;
	}
	return (result * sign);
}