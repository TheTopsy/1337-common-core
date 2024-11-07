#include<stdio.h>
#include<stdlib.h>
#include"libft.h"
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int i = 0;
	char *str;
       	if(!s)
		return NULL;
	str = malloc(ft_strlen(s) + 1);
	if(!str)
		return NULL;
	while(i < ft_strlen(s))
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return str;
}
