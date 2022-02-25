/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:39:43 by agenoves          #+#    #+#             */
/*   Updated: 2022/01/23 15:40:02 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8

# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const	char *str);
int		numline(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*readresult(int fd, char *buffer, char *temp, char *str);
char	*printbefore(char *str);
char	*prepnext(char *str);

#endif