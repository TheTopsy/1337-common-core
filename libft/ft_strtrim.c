/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:25:01 by adahab            #+#    #+#             */
/*   Updated: 2024/11/11 23:48:47 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ft_check_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	char			*q;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_check_set(s1[i], set))
		i++;
	while (j > i && ft_check_set(s1[j - 1], set))
		j--;
	q = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!q)
		return (NULL);
	q = ft_substr(s1, i, j - i);
	return (q);
}
