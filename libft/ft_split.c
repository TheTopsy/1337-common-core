/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:14:41 by adahab            #+#    #+#             */
/*   Updated: 2024/11/11 23:42:46 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	allocate(char **arr, int pos, size_t buffer)
{
	int	i;

	i = 0;
	arr[pos] = malloc(buffer);
	if (!arr[pos])
	{
		while (i < pos)
			free(arr[i++]);
		free(arr);
		return (1);
	}
	return (0);
}

static int	cpyword(char **arr, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (allocate(arr, i, len + 1))
				return (1);
			ft_strlcpy(arr[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

static size_t	count_word(char const *str, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (*str)
	{
		if (flag == 1 && *str != c)
		{
			i++;
		}
		if (*str != c)
			flag = 0;
		else
			flag = 1;
		str++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**arr;

	if (!s)
		return (NULL);
	word_count = count_word(s, c);
	arr = malloc((word_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[word_count] = NULL;
	if (cpyword(arr, s, c))
		return (NULL);
	return (arr);
}
