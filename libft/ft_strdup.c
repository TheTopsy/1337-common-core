/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:15:59 by adahab            #+#    #+#             */
/*   Updated: 2024/11/11 22:09:14 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		l;
	int		i;
	char	*str;

	l = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[l])
		l++;
	str = (char *)malloc(l + 1);
	if (!str)
		return (NULL);
	while (i < l)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
