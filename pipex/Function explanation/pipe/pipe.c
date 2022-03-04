/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:22:36 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/04 16:42:49 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// This function takes a single argument, an array of two integers (filedes).
// filedes[0] is used for reading from the pipe, and filedes[1] is used
// for writing to the pipe.
// The process which wants to read from the pipe should close filedes[1],
// and the process which wants to write to the pipe should close filedes[0].
// If the unnecessary ends of the pipe are not explicitly closed,
// then end-of-file(EOF) will never be returned.

int	main(void)
{
	int		n;
	int		filedes[2];
	char	buffer[1025];
	char	*message;

	message = "Hello, Worldddddd!";
	pipe(filedes);
	write (filedes[1], message, strlen(message));
	n = read(filedes[0], buffer, 200);
	if (n >= 0)
	{
		buffer[n] = 0;
		printf("read %d bytes from the pipe: %s\n", n, buffer);
	}
	else
		perror("read");
	exit(0);
}
