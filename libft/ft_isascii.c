#include<stdio.h>
#include<ctype.h>
int ft_isascii(int ch)
{
        if(ch >= 0 && ch <= 127)
        {
                return (1);
        }
        return (0);
}
int main()
{
        printf("%d\n", ft_isascii(128));
        printf("%d\n", isascii(128));
        return 0;
}

