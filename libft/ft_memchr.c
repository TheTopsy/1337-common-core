#include<stdio.h>
#include<string.h>
void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i = 0;
        unsigned char *p = (unsigned char *)s;
        while(i < n)
	{
		if (p[i] == c)
			return (p + i);
		i++;
        }
        return NULL;
}

