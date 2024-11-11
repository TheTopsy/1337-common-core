/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:02:53 by adahab            #+#    #+#             */
/*   Updated: 2024/11/11 15:04:14 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	n;
	char	*p;

	
	if(size && nmemb > SIZE_MAX / size)
		return (NULL);

	n = nmemb * size;
	p = (char *)malloc(n);
	while (n--)
		p[n] = 0;
	return ((void *)p);
}
