/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:47:23 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/14 17:57:30 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Questa funzione controlla se, qualora venissero passati piu di 5 argomenti,
il primo argomento (argv[1]) é "here_doc". */
int	ft_check_bonus(char *argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		return (0);
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'c' && argv[i - 1] == 'o' && argv[i - 2] == 'd' \
		&& argv[i - 3] == '_' && argv[i - 4] == 'e' && argv[i - 5] == 'r' \
		&& argv[i - 6] == 'e' && argv[i - 7] == 'h')
		return (1);
	return (0);
}
