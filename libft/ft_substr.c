#include<stdio.h>
#include<stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i = 0;
	while(s[i])
		i++;
	if(len > (i - start))
		len = (i - start);
	char *sub;
	if(start >= i)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return sub;
	}
	sub = (char *)malloc(len + 1);
	if(!sub)
		return NULL;
	i = 0;
	while(len--)
	{
		sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return sub;
}
