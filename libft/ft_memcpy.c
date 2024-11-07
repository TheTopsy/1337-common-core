#include<stdio.h>
#include <string.h>
void *ft_memcpy(void *d, const void *s, size_t n)
{
	size_t i = 0;
	char *dest = (char *) d;
	char *src = (char *) s;
	while(i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return dest;
}