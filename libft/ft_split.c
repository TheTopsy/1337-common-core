/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:14:41 by adahab            #+#    #+#             */
/*   Updated: 2024/11/08 00:15:41 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	safe_malloc(char **token_v, int position, size_t buffer)
{
	int	i;

	i = 0;
	token_v[position] = malloc(buffer);
	if (NULL == token_v[position])
	{
		while (i < position)
			free(token_v[i++]);
		free(token_v);
		return (1);
	}
	return (0);
}

int	fill(char **token_v, char const *s, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (safe_malloc(token_v, i, len + 1))
				return (1);
			ft_strlcpy(token_v[i], s - len, len + 1);
		}
		++i;
	}
	return (0);
}

size_t	count_word(char const *str, char sep)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (*str)
	{
		if (flag == 1 && *str != sep)
		{
			i++;
		}
		if (*str != sep)
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
	if (fill(arr, s, c))
		return (NULL);
	return (arr);
}
