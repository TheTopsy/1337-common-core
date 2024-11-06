#include<stdio.h>
#include<string.h>
void ft_bzero(void *s, size_t n)
{
	unsigned char *p = s;
	while(n--)
	{

		*p = 0;
		p++;

	}
}
int main()
{
	char str[3] = "sge";
	int i = 0;
	ft_bzero(str, sizeof(str));

	while(i < 3)
	{
		printf("%d", str[i]);
		i++;
	}
}
