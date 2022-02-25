/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexaupper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:38:22 by agenoves          #+#    #+#             */
/*   Updated: 2022/01/25 19:24:12 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexaupper(va_list arg)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	return (ft_putnbr_hexaupper(nb));
}
