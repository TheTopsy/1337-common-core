#include<stdio.h>
int ft_tolower(int ch)
{
	if(ch >= 'A' && ch <= 'Z')
	{
		return (ch + 32);
	}
	return (ch);
}
int main ()
{
	printf("%c", ft_tolower('z'));
}
