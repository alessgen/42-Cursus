/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:44:50 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/08 11:15:31 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_listsize(t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int	*ft_list_to_array(t_list *stack_a)
{
	int		*array;
	int		i;
	int		list_size;
	t_list	*temp;

	i = 0;
	list_size = ft_listsize(stack_a);
	if (stack_a == NULL)
		return (NULL);
	array = malloc(sizeof(int) * list_size + 1);
	temp = stack_a;
	while (temp)
	{
		array[i] = temp->data;
		temp = temp->next;
		i++;
	}
	return (array);
}

int	ft_findmedian(int *array, int size)
{
	int	median;

	if (size % 2 == 0)
		median = array[(size) / 2];
	else
		median = (array[(size - 1) / 2]);
	return (median);
}

void	ft_arraysort(int *array, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < len)
	{
		temp = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > temp)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
		i++;
	}
}
