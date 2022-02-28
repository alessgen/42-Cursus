/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:14:46 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/28 12:17:04 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_findfirst(t_list *stack_a, int position)
{
	int	first;
	int	fmove;

	first = 0;
	fmove = 0;
	while (stack_a)
	{
		if (stack_a->data < position)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (first);
}

int	ft_findsecond(t_list *stack_a, int position)
{
	int	second;
	int	temp;

	second = 0;
	temp = 0;
	while (stack_a)
	{
		if (stack_a->data < position)
			second = temp;
		temp++;
		stack_a = stack_a->next;
	}
	return (second);
}

void	ft_free_and_null(int **content)
{
	if (*content)
	{
		free(*content);
		*content = NULL;
	}
}
