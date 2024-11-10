/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:24:49 by adahab            #+#    #+#             */
/*   Updated: 2024/11/10 17:56:20 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	int	l;

	if (!str)
		return (NULL);
	l = ft_strlen(str);
	while (l >= 0)
	{
		if (str[l] == (unsigned char)c)
			return ((char *)&str[l]);
		l--;
	}
	return (NULL);
}
