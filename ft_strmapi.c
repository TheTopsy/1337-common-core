#include<stdio.h>
#include<stdlib.h>
char bzola(unsigned int i, char c)
{
	i = 1;
	c = '5';
	return c + i;
}
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int i = 0;
	char *str;
       	if(!s)
		return NULL;
	str = malloc(5);
	if(!str)
		return NULL;
	while(i < 5)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return str;
}
int main()
{
	char str[] = "abcd";
	printf("%s\n", ft_strmapi(str, bzola));
}
