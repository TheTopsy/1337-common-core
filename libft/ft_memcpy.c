/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:05:28 by adahab            #+#    #+#             */
/*   Updated: 2024/11/10 21:27:40 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t	i;
	char	*dest;
	char	*src;
	
	if(!d && !s)
		return (NULL);
	i = 0;
	dest = (char *)d;
	src = (char *)s;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
