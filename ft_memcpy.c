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
}/*
int main()
{
	char s[] = "";
	char d[20] = "123456789";
	printf("%s", (char *)memcpy(d + 3, d, 9));
	//printf("%s", (char *)ft_memcpy(d + 3, d, 9));
}*/
