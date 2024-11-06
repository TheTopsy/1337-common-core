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
int main()
{	
	char str[] = "Hello, World!";
	//printf("%s", (char *)memmove(str + 3, str, 10));
	printf("%s", (char *)ft_memmove(str  + 3, str, 10));
	//ft_memmove(str + 3, str, 10);
	//printf("%s", str);
}
