/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largearg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:26:58 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/15 19:03:51 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_splitchunks(t_list **stack_a, t_list **stack_b, t_utils *u)
{
	int	*array;

	while ((*stack_a))
	{
		array = ft_list_to_array(*stack_a);
		ft_arraysort(array, ft_listsize(*stack_a));
		u->first = ft_findfirst(*stack_a, array[20]);
		u->second = ft_findsecond(*stack_a, array[20]);
		if (u->first < ft_listsize(*stack_a) / 2)
			u->rotmoves = u->first;
		if (u->second > ft_listsize(*stack_a) / 2)
			u->secrevmoves = ft_listsize(*stack_a) - u->second;
		ft_optimizer(stack_a, stack_b, u);
	}
}

void	ft_optimizer(t_list **stack_a, t_list **stack_b, t_utils *u)
{
	int	moves;

	moves = 0;
	if (u->rotmoves <= u->secrevmoves)
	{
		moves = u->rotmoves;
		while (moves-- > 0)
			ft_rotate_a(stack_a);
		ft_push_b(stack_a, stack_b);
	}
	else if (u->secrevmoves < u->rotmoves)
	{
		moves = u->secrevmoves;
		while (moves-- > 0)
			ft_revrotate_a(stack_a);
		ft_push_b(stack_a, stack_b);
	}
}
