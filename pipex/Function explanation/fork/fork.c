/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:55:14 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/07 15:00:08 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// La funzione fork() trasforma un singolo processo in due processi
// identici riconoscibili come processo padre e figlio (Parent and Child).
// In caso di successo:
// 		Ritorna 0 al processo figlio.
// 		Process ID del processo figlio al processo padre.
// In caso di errore:
// 		Ritorna -1, non puó forkare.
//		Ritorna un numero diverso da 0 e -1 al padre.
// 		Settando errno per indicare l'errore verificatori.
// 		Non viene creato nessun processo figlio.
// Anche il processo figlio avrá un suo unico PID (Process ID).
// Tuttavia é possibile scoprire quale sia il processo figlio poiché
// come abbiamo detto il return value é 0. Quindi come si puó vedere sotto
// if (pid == 0) sará il processo figlio.

int	main(void)
{
	int	result;
	int	pid;

	result = 1;
	printf("Forking process: \n");
	pid = fork();
	pid = fork();
	pid = fork();
	pid = fork();
	if (pid < 0)
	{
		printf("Cannot fork!!\n");
	}
	if (pid == 0)
	{
		printf("Child Process ->");
	}
	else
	{
		printf("Parent Process -> ");
	}
	printf("The process id is %d and return value is %d \n", getpid(), result);
	return (0);
}
