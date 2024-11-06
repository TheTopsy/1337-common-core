#include<stdio.h>
#include<stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i = 0;
	while(s[i])
		i++;
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
		sub[i] = s[start++];
		i++;
	}
	sub[i] = '\0';
	return sub;
}
int main()
{
	char str[5] = "bzazl";
	//free(str);
	printf("%s", ft_substr(str, 10000, 156));
}
