/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:30:07 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/04 16:21:01 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
	// cmd = Path del filename del comando da eseguire
	// il Primo argomento da passare é il nome del programma, dopodiche 
	// enviromental list, scrivere env sul terminale per capire.

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
