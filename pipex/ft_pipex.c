/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:03:13 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/07 18:07:14 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HANDLING PIPE IN SHELL

#include <unistd.h>
#include <stdio.h>

int	ft_checkarg1(char *argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		return (0);
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == '1' && argv[i - 1] == 'e' && argv[i - 2] == 'l' \
		&& argv[i - 3] == 'i' && argv[i - 4] == 'f')
		return (1);
	return (0);
}

int	ft_checkarg2(char *argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		return (0);
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == '1' && argv[i - 1] == 'd' && argv[i - 2] == 'm' \
		&& argv[i - 3] == 'c')
		return (1);
	return (0);
}

int	ft_checkarg3(char *argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		return (0);
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == '2' && argv[i - 1] == 'd' && argv[i - 2] == 'm' \
		&& argv[i - 3] == 'c')
		return (1);
	return (0);
}

int	ft_checkarg4(char *argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		return (0);
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == '2' && argv[i - 1] == 'e' && argv[i - 2] == 'l' \
		&& argv[i - 3] == 'i' && argv[i - 4] == 'f')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 5)
	{
		if (ft_checkarg1(av[1]) && ft_checkarg2(av[2]) && ft_checkarg3(av[3]) \
			&& ft_checkarg4(av[4]))
		{
			printf("Ciao");
		}
		else
			printf("dio");
	}
}

// else if (ac == 6)
// 	// Bonus Part, "<<" and ">>" if av[1] == "here_doc" (./pipex here_doc LIMITER cmd1 cmd2 file);
// else if (ac > 5)
// 	// Bonus Part, Pipe multiple (./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2);
// else
// 	// Error