/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:42:39 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/24 17:14:30 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_argcheck(char *argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		return (0);
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b' \
		&& argv[i - 3] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong	sl;

	if (argc == 2)
	{
		sl.map = ft_mapread(argv[1]);
		if (ft_argcheck(argv[1]) && ft_mapchecker(&sl))
		{
			ft_gamebegin(&sl);
			ft_lets_play(&sl);
			mlx_loop(sl.mlx);
		}
		else
		{
			if (sl.map)
				free(sl.map);
			ft_print("%s", "Error\nLa mappa non è Valida");
			exit (1);
		}
	}
	else
	{
		ft_print("%s", "Error\nOggi niente sberle :P");
		exit(1);
	}
	return (0);
}
