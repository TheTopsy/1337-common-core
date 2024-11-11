/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:20:58 by adahab            #+#    #+#             */
/*   Updated: 2024/11/11 22:11:04 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sln;
	size_t	dln;
	size_t	i;
	size_t	k;

	sln = 0;
	dln = 0;
	i = 0;
	k = 0;
	if (!dst || !src)
		return (0);
	sln = ft_strlen(src);
	dln = ft_strlen(dst);
	if (size <= dln)
		return (sln + size);
	k = dln;
	while (src[i] && i < size - dln - 1)
	{
		dst[k] = src[i];
		i++;
		k++;
	}
	dst[k] = '\0';
	return (sln + dln);
}
