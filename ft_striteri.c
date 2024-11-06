#include<stdio.h>
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i = 0;
	if(!s || !f)
		return ;
	while(s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
void foo(unsigned int i, char *c)
{
	*c = '_';
	i = i + 1;
}
int main()
{
	char str[] = "";
	ft_striteri(str, foo);
	printf("%s\n", str);
}
