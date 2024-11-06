#include<stdio.h>
#include<ctype.h>
int ft_isprint(int ch)
{
        if(ch >= 33 && ch <= 126)
        {
                return (1);
        }
        return (0);
}
int main()
{
        printf("%d\n", ft_isprint(127));
        printf("%d\n", isprint(127));
        return 0;
}

