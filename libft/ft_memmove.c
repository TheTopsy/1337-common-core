/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:08:50 by adahab            #+#    #+#             */
/*   Updated: 2024/11/10 18:26:54 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *d, const void *s, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	if (!s && !d)
		return (NULL);
	dest = (unsigned char *)d;
	src = (unsigned char *)s;
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
