/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_waitpid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:51:07 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/04 17:00:42 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La funzione wait() sospende il processo corrente finche' un figlio (child)
// termina o finche' il processo corrente riceve un segnale di terminazione
// o un segnale che sia gestito da una funzione.
// Quando un child termina il processo, senza che il parent abbia atteso la sua
// terminazione attraverso la funzione di wait(), allora il child assume lo
// stato di "zombie" ossia di processo "defunto".
// Se il processo corrente esegue la funzione di wait(), mentre ci sono uno o
// piu child in stato di zombie, allora la funzione ritorna immediatamente e
// ciascuna risorsa del child viene liberata.
// La funzione waitpid() sospende il processo corrente finche' il figlio (child)
// corrispobndente al pid passato in argomento termina o finche' il processo
// corrente riceve un segnale di terminazione o un segnale che sia gestito
// da una funzione. Se il processo corrente esegue la funzione di waitpid()
// e il child identificato dal pid e' in stato di zombie, allora la
// funzione ritorna immediatamente e ciascuna risorsa del child viene liberata.
// In caso di successo le funzioni wait() e waitpid() ritornano il process ID
// del child che termina.
// Tornano -1 in caso di errore e errno viene settato in modo appropriato.
// waitpid() torna 0 se e' stato impiegato WNOHANG:
// 		WNOHANG -> specifica il ritorno immediato se i child non sono usciti.
// e non ci sono figli che hanno terminato.

// WAIT function //
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (c_pid == 0)
	{
		printf("printed from child process %d", getpid());
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("printed from parent process %d\n", getpid());
		wait(NULL);
	}
	exit(EXIT_SUCCESS);
}

// WAITPID FUNCTION //
// int	main(void)
// {
// 	pid_t	child_pid;
// 	pid_t	wtr;
// 	int		wstatus;

// 	child_pid = fork();
// 	if (child_pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (child_pid == 0)
// 	{
// 		printf("Child PID is %d\n", getpid());
// 		pause();
// 		exit(EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		wtr = waitpid(child_pid, &wstatus, WUNTRACED | WCONTINUED);
// 		if (wtr == -1)
// 		{
// 			perror("waitpid");
// 			exit(EXIT_FAILURE);
// 		}
// 		if (WIFEXITED(wstatus))
// 		{
// 			printf("exited, status=%d\n", WEXITSTATUS(wstatus));
// 		}
// 		else if (WIFSIGNALED(wstatus))
// 		{
// 			printf("killed by signal %d\n", WTERMSIG(wstatus));
// 		}
// 	}
// 	exit(EXIT_SUCCESS);
// }
