/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexalower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:38:17 by agenoves          #+#    #+#             */
/*   Updated: 2022/01/25 19:23:59 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexalower(va_list arg)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	return (ft_putnbr_hexalower(nb));
}
