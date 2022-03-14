/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:43:48 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/04 16:49:41 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La funzione unlink() elimina il pathname dal filesystem.
// Se pathname e' l'ultimo link ad un file,
// allora viene liberato anche lo spazio fisico occupato dal file.
// Se pathname si riferisce a un symbolic link, il link e' rimosso.
// La funzione unlink ritorna 0 in caso di successo e -1 in caso di fallimento.
// Libreria: <unistd.h>
// Prototipo: int unlink(const char *pathname);

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#define _POSIX_SOURCE
#undef _POSIX_SOURCE

int	main(void)
{
	int		fd;
	char	*fn;

	fn = "ciao.txt";
	fd = open(fn, S_IWUSR);
	if (fd < 0)
		perror("creat() error");
	else
	{
		close(fd);
		if (unlink(fn) != 0)
			perror("unlink() error");
	}
}
