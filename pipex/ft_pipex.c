/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:03:13 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/23 12:29:11 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HANDLING PIPE IN SHELL

#include "pipex.h"	

void	ft_childprocess(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		ft_error();
	dup2(fd[1], 1);
	dup2(filein, 0);
	close(fd[0]);
	ft_exec(argv[2], envp);
}

void	ft_parentprocess(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		ft_error();
	dup2(fd[0], 0);
	dup2(fileout, 1);
	close(fd[1]);
	ft_exec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		status;
	pid_t	par;

	if (argc == 5)
	{
		pipe(fd);
		if (pipe(fd) == -1)
			ft_error();
		par = fork();
		if (par < 0)
			ft_error();
		if (par == 0)
			ft_childprocess(argv, envp, fd);
		waitpid(par, &status, 0);
		ft_parentprocess(argv, envp, fd);
	}
	else
		ft_error();
	return (0);
}
