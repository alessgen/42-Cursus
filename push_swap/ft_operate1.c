/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:57:13 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/11 13:07:57 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap_a(t_list *stack_a)
{
	int	temp;

	if (!stack_a || !stack_a->next)
		return ;
	temp = stack_a->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = temp;
	write (1, "sa\n", 3);
}

void	ft_swap_b(t_list *stack_b)
{
	int	temp;

	if (!stack_b || !stack_b->next)
		return ;
	temp = stack_b->data;
	stack_b->data = stack_b->next->data;
	stack_b->next->data = temp;
	write (1, "sb\n", 3);
}

void	ft_swap_ab(t_list *stack_a, t_list *stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
	write (1, "ss\n", 3);
}

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_lst;

	if (!*stack_b)
		return ;
	else
	{
		temp_lst = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		temp_lst->next = *stack_a;
		*stack_a = temp_lst;
	}
	write (1, "pa\n", 3);
}

void	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_lst;

	if (!*stack_a)
		return ;
	else
	{
		temp_lst = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		temp_lst->next = *stack_b;
		*stack_b = temp_lst;
	}
	write (1, "pb\n", 3);
}
