/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:03:13 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/14 14:44:56 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HANDLING PIPE IN SHELL

#include "pipex.h"	

char	*ft_pathfinder(char *cmd, char **envp)
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
		pathnoslash = ft_strjoin(mypaths[i], "/");
		finalpath = ft_strjoin(pathnoslash, cmd);
		free(pathnoslash);
		if (access(finalpath, F_OK) == 0)
			return (finalpath);
		free(finalpath);
		i++;
	}
	ft_clean_matrix(mypaths);
	return (0);
}

void	ft_exec(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = ft_pathfinder(cmd[0], envp);
	if (!path)
	{
		ft_clean_matrix(cmd);
		ft_error();
	}
	if (execve(path, cmd, envp) == -1)
		ft_error();
}

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
