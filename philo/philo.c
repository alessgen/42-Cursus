/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:48:27 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/28 17:14:42 by agenoves         ###   ########.fr       */
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
void	*ft_create()
{
	return (0);
}

void	ft_create_thread(char *argv)
{
	int			num_philo;
	int			i;
	pthread_t	*philo;

	num_philo = atoi(argv);
	philo = malloc(sizeof(pthread_t) * num_philo);
	i = 0;
	while (i < num_philo)
	{
		pthread_create(&philo[i], NULL, ft_create, NULL);
		i++;
		printf("Thread number: %d\n", i);
	}
}

int	main(int argc, char **argv)
{
	ft_create_thread(argv[1]);
	return (0);
}
