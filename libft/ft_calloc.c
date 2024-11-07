#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
void *ft_calloc(size_t nmemb, size_t size)
{
	size_t n = nmemb * size;
	char *p = (char *)malloc(n);
	while(n--)
		p[n] = 0;
	return (void *)p;
}

