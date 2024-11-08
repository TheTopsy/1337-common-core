/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:17:09 by adahab            #+#    #+#             */
/*   Updated: 2024/11/08 00:38:09 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*allocate(char const *s1, char const *s2)
{
	int		i;
	int		l;
	char	*str;

	i = 0;
	l = 0;
	while (s1[i])
		i++;
	while (s2[l])
		l++;
	str = malloc(l + i + 1);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		l;
	char	*str;

	i = 0;
	l = 0;
	str = allocate(s1, s2);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[l])
	{
		str[i] = s2[l];
		l++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
