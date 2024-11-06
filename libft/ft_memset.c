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
int main()
{
	char s1[6] = "bzazl";
	//printf("og : %s\n", (char *)memset(s1, 'l', 9));
	printf("mine : %s", (char *)ft_memset(s1, 'l', 9));
}
