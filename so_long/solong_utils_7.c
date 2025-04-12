/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils_7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:57:22 by adahab            #+#    #+#             */
/*   Updated: 2025/04/11 14:03:34 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_format(char *str)
{
	char	ber[4];
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 3;
	i = 0;
	ber[0] = '.';
	ber[1] = 'b';
	ber[2] = 'e';
	ber[3] = 'r';
	while (str[i])
		i++;
	i--;
	while (k <= j)
	{
		if (ber[j] != str[i])
			return (0);
		i--;
		j--;
	}
	i--;
	return (1);
}

int	check_roof(char *str, int *l)
{
	int	i;

	i = 0;
	*l = 0;
	while (str[*l])
		(*l)++;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	invalid_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'P' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != '\n')
		{
			free(str);
			error_found(9);
		}
		i++;
	}
}

void	animate_p(t_mlxstuff *stuff)
{
	if (stuff->frame % 10000 < 5000)
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->character1,
			16 * stuff->char_x, 16 * stuff->char_y);
	else
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->character2,
			16 * stuff->char_x, 16 * stuff->char_y);
}
