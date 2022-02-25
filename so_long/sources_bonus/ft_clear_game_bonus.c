/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:51:06 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/24 16:02:03 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_clean_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_quit_game(t_solong *sl)
{
	ft_clean_map(sl->map);
	mlx_destroy_image(sl->mlx, sl->draw_ally);
	mlx_destroy_image(sl->mlx, sl->draw_bckg);
	mlx_destroy_image(sl->mlx, sl->draw_coll);
	mlx_destroy_image(sl->mlx, sl->draw_exit);
	mlx_destroy_image(sl->mlx, sl->draw_wall);
	mlx_destroy_window(sl->mlx, sl->window);
	free(sl->mlx);
	exit(0);
	return (0);
}
