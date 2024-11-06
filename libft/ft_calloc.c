#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
void *ft_calloc(size_t nmemb, size_t size)
{
	size_t n = nmemb * size;
	char *p = (char *)malloc(n);
	while(n--)
		p[n] = 1;
	return (void *)p;
}
int main()
{
	int n = 10;
	char *ptr = (char *)ft_calloc(10, 1);
	while(n--)
	{
		if(ptr[n] == 0)
			printf("0");
		else
			printf("!");
	}
}
