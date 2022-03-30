/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:48:27 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/30 18:29:52 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Alcune cose da sapere se vuoi riuscire nel progetto.
1) Uno o piú filosofi siedono attorno ad un tavolo rotondo e c'é un grande
   piatto di spaghetti nel centro.
2) I filosofi possono in alternativa mangiare, pensare o dormire. 
   - Quando stanno mangiando, non stanno ne pensando, ne dormendo.
   - Quando pensano, non stanno ne mangiando ne dormendo,
   - Quando dormono, non stanno ne mangiando ne pensando.
3) Ci sono anche le forchette nel tavolo, tante quanti sono i filosofi.
   Dato che servire e mangiare spaghetti con una sola forchetta é scomodo, 
   un filosofo prende sia la forchetta alla sua destra che alla usa sinistra
   per mangiare, una per mano.
4) Quando un filosofo finisce di mangiare, posa le forchette di nuovo sul
   tavolo e cominciano a dormire. Una volta svegli, ricominciano a pensare.
   La simulazione finisce quando un filosofo muore di fame.
5) Ogni filosofo ha bisogno di mangiare e non deve mai morire di fame.
6) I filosofi non parlano tra di loro.
7) I folosofi non sanno se un altro filosofo sta per morire.
8) Non c'è bisogno di dire che i filosofi dovrebbero evitare di morire. */

#include "philo.h"

/* Primo argomento:
   number_of_philosophers = Numero di filosofi e anche delle forchette.
   Secondo argomento:
   time_to_die (in millisecondi): Se un filosofo non ha iniziato a mangiare
   il time_to_die millisecondi dall'inizio del loro ultimo pasto o
   dall'inizio della simulazione, muoiono.
   Terzo argomento:
   time_to_eat (in millisecondi): Il tempo che serve a un filosofo per
   mangiare. Durante questo periodo, dovranno tenere due forchette.
   Quarto argomento:
   time_to_sleep (in millisecondi): Il tempo che un filosofo spende a dormire.
   Quinto argomento: (Opzionale)
   number_of_times_each_philosopher_must_eat: Se tutti i filosofi
   hanno mangiato almeno tot volte la simulazione si ferma. Se non specificato
   la simulazione si ferma quando filosofo muore. */

/* Bozza */
/*	Probabilmente per poter lavorare meglio é opportuno lavorare con le liste
	parlando anche con altri ragazzi siamo giunti a questa conclusione */
void	ft_define(int argc, char **argv, t_ph *ph)
{
	ph->status = 1;
	ph->num_philo = ft_atoi(argv[1]);
	ph->to_die = ft_atoi(argv[2]);
	ph->to_eat = ft_atoi(argv[3]);
	ph->to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ph->n_toeat = ft_atoi(argv[5]);
	else
		ph->n_toeat = 0;
}

void	*ft_routine(void *arg)
{
	t_list	*list;

	printf("Thread Initialized:\n");
	return (0);
}

int	ft_create_thread(t_ph *ph)
{
	int			i;
	pthread_t	*th;

	th = malloc(sizeof(pthread_t) * ph->num_philo);
	i = -1;
	while (++i < ph->num_philo)
		if (pthread_create(&th[i], NULL, ft_routine, &ph[i]) != 0)
			return (printf("Error: Thread not created!!\n"));
	i = -1;
	while (++i < ph->num_philo)
		if (pthread_join(th[i], NULL) != 0)
			return (printf("Error: Thread not Joined!!\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_ph	ph;

	if (ft_check_args(argc, argv) != 0)
		return (1);
	ft_define(argc, argv, &ph);
	ft_create_thread(&ph);
}
