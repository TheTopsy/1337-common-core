#include<stdio.h>
#include<stdlib.h>
char *ft_strjoin(char const *s1, char const *s2)
{
	int i = 0;
	int l = 0;
	while(s1[i])
		i++;
	while(s2[l])
		l++;
	char *str = malloc(l + i + 1);
	i = 0;
	l = 0;
	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while(s2[l])
	{
		str[i] = s2[l];
		l++;
		i++;
	}
	str[i] = '\0';
	return str;
}
