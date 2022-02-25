/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:07:14 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/10 16:02:22 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_splitwithmed(t_list **stack_a, t_list **stack_b, int median)
{
	int	num_of_iteration;
	int	i;
	int	*array;

	i = 0;
	num_of_iteration = ft_listsize(*stack_a) / 2;
	while (ft_listsize(*stack_a) > 2)
	{
		if (i == num_of_iteration)
		{
			array = ft_list_to_array(*stack_a);
			ft_arraysort(array, ft_listsize(*stack_a));
			median = ft_findmedian(array, ft_listsize(*stack_a));
			free(array);
			num_of_iteration = ft_listsize(*stack_a) / 2;
			i = 0;
		}
		if ((*stack_a)->data < median)
		{
			ft_push_b(stack_a, stack_b);
			i++;
		}
		else
			ft_rotate_a(stack_a);
	}
}

void	ft_threenumb(t_list **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data)
		ft_swap_a(*stack_a);
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data)
		ft_rotate_a(stack_a);
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->data)
	{
		ft_swap_a(*stack_a);
		ft_revrotate_a(stack_a);
	}
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data)
	{
		ft_swap_a(*stack_a);
		ft_rotate_a(stack_a);
	}
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->data)
		ft_revrotate_a(stack_a);
}

void	ft_firstcheck(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_swap_a(*stack_a);
	ft_push_a(stack_a, stack_b);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_swap_a(*stack_a);
	if ((*stack_a)->data < (*stack_b)->data)
	{
		ft_push_b(stack_a, stack_b);
		ft_swap_b(*stack_b);
		ft_push_a(stack_a, stack_b);
	}
}

void	ft_sorts(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	max;
	int	moves;

	while (*stack_b)
	{
		max = ft_findmax(stack_b, ft_listsize(*stack_b));
		index = ft_indexing(*stack_b, max);
		if ((*stack_b)->data == max)
			ft_push_a(stack_a, stack_b);
		else if (index < ft_listsize(*stack_b) / 2)
		{
			moves = index;
			while (moves-- > 0)
				ft_rotate_b(stack_b);
		}
		else
		{
			moves = ft_listsize(*stack_b) - index;
			while (moves-- > 0)
				ft_revrotate_b(stack_b);
		}
	}
}
