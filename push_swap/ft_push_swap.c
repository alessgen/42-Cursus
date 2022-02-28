/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:33:11 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/28 12:23:10 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_fill_the_stack(int argc, char **argv, t_utils *utils)
{
	utils->i = 1;
	utils->stack_b = NULL;
	utils->stack_a = NULL;
	while (utils->i < argc)
	{
		utils->a = ft_split(argv[utils->i], ' ');
		utils->j = 0;
		while (utils->a[utils->j])
		{
			utils->data = ft_atoi(utils->a[utils->j]);
			if (!ft_checkdigit(utils->data, utils->a[utils->j]))
				return (0);
			ft_lstadd_back(&utils->stack_a, ft_lstnew(utils->data));
			utils->j++;
		}
		ft_clearmatrix(utils->a);
		utils->i++;
	}
	return (1);
}

void	ft_clearleak(t_utils *utils)
{
	t_list	*temp;

	while (utils->stack_a)
	{
		temp = utils->stack_a->next;
		free(utils->stack_a);
		utils->stack_a = temp;
	}
	if (utils->array)
		free(utils->array);
}

void	ft_clearmatrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

int	main(int argc, char **argv)
{
	t_utils	utils;

	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strlen(argv[1]) == 0)
		return (0);
	if (!ft_fill_the_stack(argc, argv, &utils))
	{
		write (1, "Error\n", 6);
		ft_clearleak(&utils);
		return (0);
	}
	if (!ft_checkdouble(&utils))
	{
		write (1, "Error\n", 6);
		ft_clearleak(&utils);
		return (0);
	}
	if (!ft_isordered(utils.stack_a))
		ft_checkargs(&utils);
	ft_clearleak(&utils);
}
