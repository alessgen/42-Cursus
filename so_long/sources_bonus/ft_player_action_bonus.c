/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_action_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenoves <agenoves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:38:23 by agenoves          #+#    #+#             */
/*   Updated: 2022/02/25 18:47:06 by agenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_change_ally_img(int key, t_solong *sl)
{
	mlx_destroy_image(sl->mlx, sl->draw_ally);
	if (key == 13)
		sl->draw_ally = mlx_xpm_file_to_image(sl->mlx, "./Images/ally.xpm",
				&sl->img_w, &sl->img_h);
	else if (key == 1)
		sl->draw_ally = mlx_xpm_file_to_image(sl->mlx, "./Images/allyupd.xpm",
				&sl->img_w, &sl->img_h);
	else if (key == 0)
		sl->draw_ally = mlx_xpm_file_to_image(sl->mlx, "./Images/allyupd.xpm",
				&sl->img_w, &sl->img_h);
	else if (key == 2)
		sl->draw_ally = mlx_xpm_file_to_image(sl->mlx, "./Images/ally.xpm",
				&sl->img_w, &sl->img_h);
}

void	ft_player_w(t_solong *sl)
{
	ft_change_ally_img(13, sl);
	if (sl->map[sl->ally_y][sl->ally_x] == 'E' && sl->map_coll == 0)
	{
		mlx_clear_window(sl->mlx, sl->window);
		sl->map[sl->ally_y + 1][sl->ally_x] = '0';
		sl->moves++;
		sl->stopgame = 1;
		ft_win_game(sl);
	}	
	else if (sl->map[sl->ally_y][sl->ally_x] == '1' \
		|| sl->map[sl->ally_y][sl->ally_x] == 'E')
		sl->ally_y += 1;
	else if (sl->map[sl->ally_y][sl->ally_x] == 'N')
		ft_lose_game(sl);
	else
	{
		mlx_clear_window(sl->mlx, sl->window);
		if (sl->map[sl->ally_y][sl->ally_x] == 'C')
			sl->map_coll = sl->map_coll - 1;
		sl->map[sl->ally_y][sl->ally_x] = 'P';
		sl->map[sl->ally_y + 1][sl->ally_x] = '0';
		sl->moves++;
		ft_map_updt(sl);
	}
}

void	ft_player_a(t_solong *sl)
{
	ft_change_ally_img(0, sl);
	if (sl->map[sl->ally_y][sl->ally_x] == 'E' && sl->map_coll == 0)
	{
		mlx_clear_window(sl->mlx, sl->window);
		sl->map[sl->ally_y][sl->ally_x + 1] = '0';
		sl->moves++;
		sl->stopgame = 1;
		ft_win_game(sl);
	}
	else if (sl->map[sl->ally_y][sl->ally_x] == '1' \
		|| sl->map[sl->ally_y][sl->ally_x] == 'E')
		sl->ally_x += 1;
	else if (sl->map[sl->ally_y][sl->ally_x] == 'N')
		ft_lose_game(sl);
	else
	{
		mlx_clear_window(sl->mlx, sl->window);
		if (sl->map[sl->ally_y][sl->ally_x] == 'C')
			sl->map_coll -= 1;
		sl->map[sl->ally_y][sl->ally_x] = 'P';
		sl->map[sl->ally_y][sl->ally_x + 1] = '0';
		sl->moves++;
		ft_map_updt(sl);
	}
}

void	ft_player_s(t_solong *sl)
{
	ft_change_ally_img(1, sl);
	if (sl->map[sl->ally_y][sl->ally_x] == 'E' && sl->map_coll == 0)
	{
		mlx_clear_window(sl->mlx, sl->window);
		sl->map[sl->ally_y - 1][sl->ally_x] = '0';
		sl->moves++;
		sl->stopgame = 1;
		ft_win_game(sl);
	}
	else if (sl->map[sl->ally_y][sl->ally_x] == '1' \
		|| sl->map[sl->ally_y][sl->ally_x] == 'E')
		sl->ally_y -= 1;
	else if (sl->map[sl->ally_y][sl->ally_x] == 'N')
		ft_lose_game(sl);
	else
	{
		mlx_clear_window(sl->mlx, sl->window);
		if (sl->map[sl->ally_y][sl->ally_x] == 'C')
			sl->map_coll = sl->map_coll - 1;
		sl->map[sl->ally_y][sl->ally_x] = 'P';
		sl->map[sl->ally_y - 1][sl->ally_x] = '0';
		sl->moves++;
		ft_map_updt(sl);
	}
}

void	ft_player_d(t_solong *sl)
{
	ft_change_ally_img(2, sl);
	if (sl->map[sl->ally_y][sl->ally_x] == 'E' && sl->map_coll == 0)
	{
		mlx_clear_window(sl->mlx, sl->window);
		sl->map[sl->ally_y][sl->ally_x - 1] = '0';
		sl->moves++;
		sl->stopgame = 1;
		ft_win_game(sl);
	}
	else if (sl->map[sl->ally_y][sl->ally_x] == '1' \
		|| sl->map[sl->ally_y][sl->ally_x] == 'E')
		sl->ally_x -= 1;
	else if (sl->map[sl->ally_y][sl->ally_x] == 'N')
		ft_lose_game(sl);
	else
	{
		mlx_clear_window(sl->mlx, sl->window);
		if (sl->map[sl->ally_y][sl->ally_x] == 'C')
			sl->map_coll -= 1;
		sl->map[sl->ally_y][sl->ally_x] = 'P';
		sl->map[sl->ally_y][sl->ally_x - 1] = '0';
		sl->moves++;
		ft_map_updt(sl);
	}
}
