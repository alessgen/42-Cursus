/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:56:28 by agenoves          #+#    #+#             */
/*   Updated: 2022/03/01 18:59:33 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_draw_moves(t_solong *sl)
{
	char	*str;

	str = ft_itoa(sl->moves);
	mlx_string_put(sl->mlx, sl->window, 25, 20, 0x00FFFFFF, "Moves: ");
	mlx_string_put(sl->mlx, sl->window, 85, 20, 0x00FFFFFF, str);
	free(str);
}

void	ft_enemy_moves(t_solong *sl)
{
	sl->enemy_x -= 1;
	if (sl->map[sl->enemy_y][sl->enemy_x] == '1')
		sl->enemy_x += 1;
	else if (sl->map[sl->enemy_y][sl->enemy_x] == '0')
	{
		sl->map[sl->enemy_y][sl->enemy_x] = 'N';
		sl->map[sl->enemy_y][sl->enemy_x + 1] = '0';
	}
}
