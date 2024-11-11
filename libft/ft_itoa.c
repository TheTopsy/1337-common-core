/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:48:37 by adahab            #+#    #+#             */
/*   Updated: 2024/11/11 19:01:55 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*convertn(int n, int i, char *str)
{
	str[i] = '\0';
	i--;
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (str);
}

char	*n_iszero(void)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*n_ismin(void)
{
	char	*intmin;
	char	*str;
	int		i;

	intmin = "-2147483648";
	str = malloc(12);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (intmin[i])
	{
		str[i] = intmin[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	count_digit(int n)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = n;
	while (tmp != 0)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (n_ismin());
	if (n == 0)
		return (n_iszero());
	i = count_digit(n);
	if (n < 0)
	{
		i++;
		str = malloc(i + 1);
		if (!str)
			return (NULL);
		str[0] = '-';
		n = -n;
	}
	else
	{
		str = malloc(i + 1);
		if (!str)
			return (NULL);
	}
	return (convertn(n, i, str));
}
