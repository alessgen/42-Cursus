/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexaupper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:24:40 by agenoves          #+#    #+#             */
/*   Updated: 2022/01/25 19:30:06 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexaupper(unsigned int nb)
{
	char	*hexa;
	int		output;

	hexa = "0123456789ABCDEF";
	output = 0;
	if (nb > 15)
		output += output + ft_putnbr_hexaupper(nb / 16);
	output += write(1, &hexa[nb % 16], 1);
	return (output);
}
