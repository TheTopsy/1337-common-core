/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:53:51 by adahab            #+#    #+#             */
/*   Updated: 2025/04/11 13:54:22 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_next_tile(t_mlxstuff *stuff, char dir)
{
	if (dir == 6 && stuff->char_x < get_width(stuff->str)
		&& stuff->map[stuff->char_y][stuff->char_x + 1] != '1')
	{
		interact(stuff, dir);
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->ground, 16
			* stuff->char_x, 16 * stuff->char_y);
		stuff->char_x++;
		ft_printf("moves : %d\n", ++stuff->moves);
	}
	else if (dir == 4 && stuff->char_x > 0
		&& stuff->map[stuff->char_y][stuff->char_x - 1] != '1')
	{
		interact(stuff, dir);
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->ground, 16
			* stuff->char_x, 16 * stuff->char_y);
		stuff->char_x--;
		ft_printf("moves : %d\n", ++stuff->moves);
	}
	else
		up_down(stuff, dir);
}

int	key_hook(int keycode, t_mlxstuff *stuff)
{
	if (keycode == 65363)
		check_next_tile(stuff, 6);
	if (keycode == 65361)
		check_next_tile(stuff, 4);
	if (keycode == 65364)
		check_next_tile(stuff, 2);
	if (keycode == 65362)
		check_next_tile(stuff, 8);
	if (keycode == 65307)
		close_window(stuff);
	return (0);
}

void	initialize_stuff(t_mlxstuff **stuff, int collectables, char *str)
{
	(*stuff) = malloc(sizeof(t_mlxstuff));
	if (!(*stuff))
		exit(EXIT_FAILURE);
	(*stuff)->currentc = 0;
	(*stuff)->mlx = mlx_init();
	if (!(*stuff)->mlx)
		exit(0);
	(*stuff)->mlx_win = mlx_new_window((*stuff)->mlx, get_width(str) * 16,
			get_height(str) * 16, "game");
	if (!(*stuff)->mlx_win)
		exit(0);
	set_sprites((*stuff));
	(*stuff)->pot_x = malloc(collectables * sizeof(int));
	if (!(*stuff)->pot_x)
		exit(0);
	(*stuff)->pot_y = malloc(collectables * sizeof(int));
	if (!(*stuff)->pot_y)
		exit(0);
	(*stuff)->potcount = collectables;
	(*stuff)->str = str;
	(*stuff)->i = 0;
	(*stuff)->v = 0;
	(*stuff)->p = 0;
	(*stuff)->moves = 0;
}

int	display_tile(t_mlxstuff *stuff, char **map)
{
	if (map[stuff->i][stuff->v] == '0')
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->ground, 16
			* stuff->v, 16 * stuff->i);
	else if (map[stuff->i][stuff->v] == '1')
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->wall, 16
			* stuff->v, 16 * stuff->i);
	else if (map[stuff->i][stuff->v] == 'P')
	{
		stuff->char_x = stuff->v;
		stuff->char_y = stuff->i;
	}
	else if (map[stuff->i][stuff->v] == 'E')
	{
		stuff->por_x = stuff->v;
		stuff->por_y = stuff->i;
	}
	else if (map[stuff->i][stuff->v] == 'C')
	{
		stuff->pot_x[stuff->p] = stuff->v;
		stuff->pot_y[stuff->p] = stuff->i;
		return (1);
	}
	return (0);
}

void	display_map(char **map, int collectables, char *str)
{
	t_mlxstuff	*stuff;

	initialize_stuff(&stuff, collectables, str);
	stuff->map = map;
	while (map[stuff->i])
	{
		while (map[stuff->i][stuff->v])
		{
			if (display_tile(stuff, map))
				stuff->p++;
			stuff->v++;
		}
		stuff->v = 0;
		stuff->i++;
	}
	stuff->frame = 0;
	mlx_hook(stuff->mlx_win, 17, 0, close_window, stuff);
	mlx_loop_hook(stuff->mlx, animate, stuff);
	mlx_key_hook(stuff->mlx_win, key_hook, stuff);
	mlx_loop(stuff->mlx);
}
