/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>             +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:09:37 by adahab            #+#    #+#             */
/*   Updated: 2024/12/31 15:38:11 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	l;

	l = 0;
	if (!s)
		return (0);
	while (s[l])
		l++;
	return (l);
}

char	*ft_strndup(char *s, size_t n)
{
	size_t	i;
	char	*output;

	i = 0;
	output = malloc(n + 1);
	if (!output)
		return (NULL);
	while (i < n)
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	char	*output;

	i = 0;
	output = malloc(ft_strlen(s) + 1);
	if (!output)
		return (NULL);
	while (s[i])
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_s2;
	size_t	len_s1;
	char	*output;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	output = malloc(sizeof(char *) * (len_s1 + len_s2 + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		output[i++] = s2[j++];
	free(s1);
	output[i] = '\0';
	return (output);
}

char	*ft_strchr(const char *s, int ch)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)ch)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
