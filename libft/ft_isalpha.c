#include<stdio.h>
#include<ctype.h>
int ft_isalpha(int ch)
{
	if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	{
		return (1);
	}
	return (0);
}
int main()
{
	printf("%d\n", ft_isalpha('j'));
	//printf("%d\n", isalpha('j'));
	return 0;
}
