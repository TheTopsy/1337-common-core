#include <string.h>
#include<stdio.h>
void *ft_memset(void *s, int c, size_t n)
{
	unsigned char *p = (unsigned char *)s;
	size_t i = 0;
	while(n--)
	{
    	    p[i] = c;
	    i++;
	}
	return (void *)p;
}