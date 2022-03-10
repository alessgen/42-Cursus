/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:03:13 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/10 18:45:09 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HANDLING PIPE IN SHELL

#include "pipex.h"	

char	**ft_pathfinder(char *cmd, char **envp)
{
	char	**mypaths;
	char	*pathnoslash;
	char	*pathinenv;
	char	*finalpath;
	int		i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	pathinenv = envp[i] + 5;
	mypaths = ft_split(pathinenv, ':');
	i = 0;
	while (mypaths[i])
	{
		pathnoslash = ft_strjoin(mypaths[i], '/');
		finalpath = ft_strjoin(pathnoslash, cmd);
		free(pathnoslash);
		if (access(finalpath, F_OK) == 0)
			return (finalpath);
		i++;
		free(finalpath);
	}
	ft_clean_matrix(mypaths);
	return (0);
}

void	ft_childprocess(char **argv, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		perror("Error ");
	dup2(filein, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	// Eseguire ARGV[2];
	close(filein);
}

void	ft_parentprocess(char **argv, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC | 0644);
	if (fileout == -1)
		perror("Error ");
	dup2(fileout, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	// Eseguire ARGV[3]
	close(fileout);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	par;

	if (argc == 5)
	{
		pipe(fd);
		if (pipe(fd) == -1)
			perror("Cannot create File Descriptor ");
		par = fork();
		if (par < 0)
			perror("Cannot fork ");
		if (par == 0)
			ft_childprocess(argv, fd);
		waitpid();
		ft_parentprocess(argv, fd);
	}
	else
	{
		perror("Invalid argument ");
		// Se vogliamo inserire un write o printf o perror dove spieghi 
		//come compilare ("You should compile: ./pipex file1 cmd1 cmd2 file2")
	}
