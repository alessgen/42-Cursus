/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testaccess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:44:31 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/04 11:55:15 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	int		result;
	char	*path;

	path = "./ciao.txt"; 		 // Path del file da controllare.
	result = access(path, W_OK); // Viene verificata l'esistenza di pathname
								 //	ed il permesso in scrittura del file 
	if (result == 0)
		write (1, "Ciao\n", 5);
	else
		write (1, "col cazzo\n", 10);
	result = access(path, R_OK); //Viene verificata l'esistenza di pathname
								 //ed il permesso in lettura
	if (result == 0)
		write (1, "Ciao\n", 5);
	else
		write (1, "col cazzo\n", 10);
	result = access(path, X_OK); // Viene verificata l'esistenza di pathname 
								 // ed il permesso di esecuzione
	if (result == 0)
		write (1, "Ciao\n", 5);
	else
		write (1, "col cazzo\n", 10);
	result = access(path, F_OK); // Viene verificata l'esistenza di pathname
	if (result == 0)
		write (1, "Ciao\n", 5);
	else
		write (1, "col cazzo\n", 10);
}
