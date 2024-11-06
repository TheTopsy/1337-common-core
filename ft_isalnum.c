#include<stdio.h>
#include<ctype.h>
int ft_isalnum(int ch)
{
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
                return (1);
        }
        return (0);
}
int main()
{
        printf("%d\n", ft_isalnum('p'));
	printf("%d\n", ft_isalnum('/'));
        printf("%d\n", ft_isalnum('1'));
        return 0;
}

