#include <string.h>
#include<stdio.h>
void *ft_memmove(void *d, const void *s, size_t n)
{
	char *dest = (char *)d;
	char *src = (char *)s; 
	if(dest <= src)
	{
		while(n--)
		{
			*dest++ = *src++;
		}
	}
	else
	{
		while(n--)
		{
			dest[n] = src[n];
		}
	}
	return d;
}