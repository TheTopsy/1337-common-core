#include<stdio.h>
#include<string.h>
#include<stdlib.h>
size_t ft_strlen(char *s)
{
	size_t i = 0;
	while(s[i])
		i++;
	return i;
}
char *ft_strrchr(const char *str, int c)
{
        int i = ft_strlen((char *)str);
       		while(i >= 0 && str[i] != c)
                {
			i--;
		}	
		if(i< 0)
			return NULL;
        str += i;
	return (char *)str;
}

