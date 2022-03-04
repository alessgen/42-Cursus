/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testdup2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:03:48 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/04 16:18:24 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
	// Dentro input saranno presenti due numeri che verranno scannerizzati con
	// scanf. Dopodiché con la funzione dup2 setto come default il file
	// input.txt come standard input file descriptor.
	// Dopodiche con la funzione dup2 invece imposto il file output.txt come 
	// default di standard di output cosicché quando verra eseguito il programma
	// il risultato riportato da printf sará scritto dentro output.txt e non
	// sul default standard output (ossia lo schermo/shell)

int	main(void)
{
	int	number1;
	int	number2;
	int	sum;
	int	input_fds;
	int	output_fds;

	input_fds = open("./input.txt", O_RDONLY);
	output_fds = open("./output.txt", O_WRONLY | O_CREAT);
	dup2(input_fds, 0);
	dup2(output_fds, 1);
	scanf("%d %d", &number1, &number2);
	sum = number1 + number2;
	printf("%d + %d = %d\n", number1, number2, sum);
	return (EXIT_SUCCESS);
}
