/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:51:46 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/14 18:28:39 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "pipex.h"
# include "utils/get_next_line.h"

/* Utils and Check */
int		ft_check_bonus(char *argv);
/* Execution */
void	ft_here_doc(char *limiter, int *fd);

#endif