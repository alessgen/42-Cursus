/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:59:32 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/24 17:56:03 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

int	ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s) + 1;
	i = 0;
	while (i < len)
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}
