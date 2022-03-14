/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:42:43 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/14 18:33:32 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* Funzione che prende come parametri il limiter (argv[2]) e controlla, con 
get_next_line dello stdout (shell) se appare la stringa limiter, confrontandola
con strncmp o strnstr */
void	ft_here_doc(char *limiter, int *fd)
{
	char	*line;

	while (get_next_line(0))
	{
		line = get_next_line(0);
		if (ft_strncmp(limiter, line, ft_strlen(limiter)) == 0)
			exit(0);
		write(fd[1], line, ft_strlen(line));
	}	
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	fileout;
	int	filein;
	int	i;	

	if (argc > 5)
	{
		if (ft_check_bonus(argv[1]))
		{
			i = 3;
			fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
			ft_here_doc(argv[2], fd);
		}
		else
		{
			i = 2;
			filein = open(argv[1], O_RDONLY, 0777);
			fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		}
		while (i < argc - 1)
			ft_childprocess(argv[i++], envp, fd);
	}
	else
		ft_error();
}
