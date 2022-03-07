/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:30:07 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/07 11:15:05 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
	// cmd = Path del filename del comando da eseguire
	// il Primo argomento da passare é il nome del programma, dopodiche gli 
	// altri argomenti interessati e, l'ultimo argomento, deve essere un NULL
	// carattere per concludere.
	// enviromental list, scrivere env sul terminale per capire, anche in 
	// questo caso, l'ultimo deve essere un NULL carattere.

int	main(void)
{
	char	cmd[] = "./args.out";
	char	*argv[] = {"args.out", NULL};
	char	*env[] = {NULL};

	printf("Start of execve %s:\n", cmd);
	printf("==========================================\n");
	if (execve(cmd, argv, env) == -1)
		perror("Che palle");
	printf("Oops, errore");
}
