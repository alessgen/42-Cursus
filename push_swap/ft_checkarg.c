/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:10:02 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/28 12:46:51 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_checkdigit(long result, char *str)
{
	if (result < -2147483648 || result > 2147483647)
		return (0);
	if (result != 0)
		return (1);
	else
	{
		if (ft_strlen(str) == 2)
		{
			if (str[0] == '-' && str[1] == '0')
				return (1);
			return (0);
		}
		else if (ft_strlen(str) > 1)
			return (0);
		if (str[0] == '0')
			return (1);
		return (0);
	}
}

int	ft_checkdouble(t_utils *utils)
{
	utils->i = 0;
	utils->count = ft_listsize(utils->stack_a);
	utils->array = ft_list_to_array(utils->stack_a);
	while (utils->i < utils->count - 1)
	{
		utils->j = utils->i + 1;
		while (utils->j < utils->count)
		{
			if (utils->array[utils->i] == utils->array[utils->j])
			{
				ft_free_and_null(&utils->array);
				return (0);
			}
			utils->j++;
		}
		utils->i++;
	}
	ft_free_and_null(&utils->array);
	return (1);
}

void	ft_twonumb(t_list **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_swap_a(*stack_a);
}

void	ft_checkargs(t_utils *utils)
{
	if (ft_listsize((*utils).stack_a) == 2)
		ft_twonumb(&utils->stack_a);
	else if (ft_listsize((*utils).stack_a) == 3)
		ft_threenumb(&utils->stack_a);
	else if (ft_listsize((*utils).stack_a) == 5)
		ft_fivenumb(&utils->stack_a, &utils->stack_b);
	else if (ft_listsize((*utils).stack_a) > 3
		&& (ft_listsize((*utils).stack_a) < 101))
	{
		(*utils).array = ft_list_to_array((*utils).stack_a);
		ft_arraysort((*utils).array, ft_listsize((*utils).stack_a));
		(*utils).median = ft_findmedian((*utils).array,
				ft_listsize((*utils).stack_a));
		ft_splitwithmed(&(*utils).stack_a, &(*utils).stack_b, (*utils).median);
		ft_firstcheck(&(*utils).stack_a, &(*utils).stack_b);
		ft_sorts(&(*utils).stack_a, &(*utils).stack_b);
	}
	else if (ft_listsize((*utils).stack_a) > 100)
	{
		ft_splitchunks(&(*utils).stack_a, &(*utils).stack_b, utils);
		ft_sorts(&(*utils).stack_a, &(*utils).stack_b);
	}
}

int	ft_isordered(t_list *stack_a)
{
	t_list	*list;
	int		value;

	list = stack_a;
	value = list->data;
	while (list)
	{
		if (value > list->data)
			return (0);
		value = list->data;
		list = list->next;
	}
	return (1);
}
