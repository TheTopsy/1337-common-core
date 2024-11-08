/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:16:07 by adahab            #+#    #+#             */
/*   Updated: 2024/11/08 00:16:08 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (str[l])
		l++;
	while (str[i] != c && str[i])
		i++;
	if (i == l)
		return (NULL);
	return ((char *)str + i);
}
