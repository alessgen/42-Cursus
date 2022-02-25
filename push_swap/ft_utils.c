/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:15:46 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/10 16:04:47 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_revrotate_ab(t_list **stack_a, t_list **stack_b)
{
	ft_revrotate_a(stack_a);
	ft_revrotate_b(stack_b);
	write (1, "rrr\n", 4);
}

int	ft_findmax(t_list **stack_b, int size)
{
	int	max;
	int	*array;

	max = 0;
	array = ft_list_to_array(*stack_b);
	ft_arraysort(array, ft_listsize(*stack_b));
	max = array[size - 1];
	if (array)
		free(array);
	return (max);
}

int	ft_findmin(t_list **stack_a)
{
	int	min;
	int	*array;

	array = ft_list_to_array(*stack_a);
	ft_arraysort(array, ft_listsize(*stack_a));
	min = array[0];
	if (array)
		free(array);
	return (min);
}

int	ft_indexing(t_list *list, int max)
{
	int	i;

	i = 0;
	while (list->next != NULL)
	{
		if (list->data == max)
			return (i);
		i++;
		list = list->next;
	}
	return (i);
}
