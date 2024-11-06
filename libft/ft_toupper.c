#include<stdio.h>
int ft_toupper(int ch)
{
	if(ch >= 'a' && ch <= 'z')
	{
		return (ch - 32);
	}
	return (ch);
}
int main()
{
	printf("%c", ft_toupper('n'));
	return 0;
}
