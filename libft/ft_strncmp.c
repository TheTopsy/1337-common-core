#include<stdio.h>
#include<string.h>
int ft_strncmp(const char *s1,const char *s2, size_t n)
{
	size_t i = 0;
	while(n--)
	{
		
		if (s1[i] == s2[i] && s1[i] && s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}