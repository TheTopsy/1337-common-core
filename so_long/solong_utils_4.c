/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:50:48 by adahab            #+#    #+#             */
/*   Updated: 2025/04/11 13:53:30 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	animate(t_mlxstuff *stuff)
{
	stuff->frame++;
	animate_p(stuff);
	if (stuff->frame % 10000 < 5000)
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->portal1, 16
			* stuff->por_x, 16 * stuff->por_y);
	else if (stuff->frame % 10000 >= 5000)
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->portal2, 16
			* stuff->por_x, 16 * stuff->por_y);
	if (stuff->frame % 10000 < 5000 && stuff->por_x == stuff->char_x
		&& stuff->por_y == stuff->char_y)
	{
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->portal3, 16
			* stuff->por_x, 16 * stuff->por_y);
		if (stuff->currentc == stuff->potcount)
			close_window(stuff);
	}
	else if (stuff->frame % 10000 >= 5000 && stuff->por_x == stuff->char_x
		&& stuff->por_y == stuff->char_y)
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->portal4, 16
			* stuff->por_x, 16 * stuff->por_y);
	animate_potions(stuff);
	return (0);
}

void	collect_potion(t_mlxstuff *stuff, int i)
{
	stuff->pot_x[i] = -10;
	stuff->currentc++;
}

void	left_right(t_mlxstuff *stuff, char dir)
{
	int	i;

	i = 0;
	if (dir == 6)
	{
		while (i < stuff->potcount)
		{
			if (stuff->pot_x[i] == stuff->char_x + 1
				&& stuff->pot_y[i] == stuff->char_y)
				collect_potion(stuff, i);
			i++;
		}
	}
	else if (dir == 4)
	{
		while (i < stuff->potcount)
		{
			if (stuff->pot_x[i] == stuff->char_x - 1
				&& stuff->pot_y[i] == stuff->char_y)
				collect_potion(stuff, i);
			i++;
		}
	}
}

void	interact(t_mlxstuff *stuff, char dir)
{
	int	i;

	i = 0;
	left_right(stuff, dir);
	if (dir == 8)
	{
		while (i < stuff->potcount)
		{
			if (stuff->pot_x[i] == stuff->char_x
				&& stuff->pot_y[i] == stuff->char_y - 1)
				collect_potion(stuff, i);
			i++;
		}
	}
	else if (dir == 2)
	{
		while (i < stuff->potcount)
		{
			if (stuff->pot_x[i] == stuff->char_x
				&& stuff->pot_y[i] == stuff->char_y + 1)
				collect_potion(stuff, i);
			i++;
		}
	}
}

void	up_down(t_mlxstuff *stuff, char dir)
{
	if (dir == 8 && stuff->char_y > 0 && stuff->map
		[stuff->char_y - 1][stuff->char_x] != '1')
	{
		interact(stuff, dir);
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->ground, 16
			* stuff->char_x, 16 * stuff->char_y);
		stuff->char_y--;
		ft_printf("moves : %d\n", ++stuff->moves);
	}
	else if (dir == 2 && stuff->char_y < get_height(stuff->str)
		&& stuff->map[stuff->char_y + 1][stuff->char_x] != '1')
	{
		interact(stuff, dir);
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->ground, 16
			* stuff->char_x, 16 * stuff->char_y);
		stuff->char_y++;
		ft_printf("moves : %d\n", ++stuff->moves);
	}
}
