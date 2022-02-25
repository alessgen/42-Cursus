/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexalower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:24:40 by agenoves          #+#    #+#             */
/*   Updated: 2022/01/25 19:34:40 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexalower(unsigned int nb)
{
	char	*hexa;
	int		output;

	hexa = "0123456789abcdef";
	output = 0;
	if (nb > 15)
		output += output + ft_putnbr_hexalower(nb / 16);
	output += write(1, &hexa[nb % 16], 1);
	return (output);
}
