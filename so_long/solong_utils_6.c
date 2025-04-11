/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils_6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:54:40 by adahab            #+#    #+#             */
/*   Updated: 2025/04/11 13:57:00 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	countc(char *str)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			c++;
		i++;
	}
	return (c);
}

void	init_counts(t_counts *counts)
{
	counts->ccount = 0;
	counts->ecount = 0;
}

void	strtomap(char *str)
{
	char		**map;
	int			i;
	t_counts	*counts;

	map = NULL;
	counts = malloc(sizeof(t_counts));
	init_counts(counts);
	i = 0;
	allocate_map(&map, str);
	fill_map(&map, str);
	if (flood_check(map, str, counts))
	{
		fill_map(&map, str);
		free(counts);
		display_map(map, countc(str), str);
	}
	else
	{
		while (map[i])
			free(map[i++]);
		free(map);
		free(str);
		free(counts);
		error_found(7);
	}
}

int	is_rectangular(char *map)
{
	int	i;
	int	lines;
	int	line_length;

	i = 0;
	lines = 0;
	line_length = 0;
	while (map[line_length] != '\n')
		line_length++;
	while (map[i])
	{
		if (map[i] == '\n')
			lines++;
		i++;
	}
	lines++;
	i++;
	if ((i - lines) == (lines * line_length))
		return (1);
	return (0);
}

int	check_map(char *map)
{
	int		i;
	int		collectable;
	char	start;
	char	exit;

	i = 0;
	collectable = 0;
	exit = 0;
	start = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			collectable++;
		if (map[i] == 'E')
			exit++;
		if (map[i] == 'P')
			start++;
		i++;
	}
	if (collectable >= 1 && exit == 1 && start == 1)
		return (1);
	return (0);
}
