#include<string.h>
#include<stdlib.h>
#include<stdio.h>
char *ft_strdup(const char *s)
{
	int l = 0;
	int i = 0;
	while(s[l])
		l++;
	char *str = (char *)malloc(l + 1);
	if(!str)
		return NULL;
	while(i < l)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return str;
}
