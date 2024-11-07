#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"libft.h"
int	ft_check_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int i = 0;
	unsigned int j = ft_strlen(s1);
	char	*q;
	while(s1[i] && ft_check_set(s1[i], set))
		i++;
	while (j > i && ft_check_set(s1[j - 1], set))
		j--;
	q = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!q)
		return (NULL);
	q = ft_substr(s1, i, j - i);
	return (q);
}
