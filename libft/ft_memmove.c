/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:08:50 by adahab            #+#    #+#             */
/*   Updated: 2024/11/08 00:08:55 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *d, const void *s, size_t n)
{
	char	*dest;
	char	*src;

	dest = (char *)d;
	src = (char *)s;
	if (dest <= src)
	{
		while (n--)
		{
			*dest++ = *src++;
		}
	}
	else
	{
		while (n--)
		{
			dest[n] = src[n];
		}
	}
	return (d);
}
