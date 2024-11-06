#include<stdio.h>
int ft_isdigit(int ch)
{
        if(ch >= '0' && ch <= '9')
        {
                return (1);
        }
        return (0);
}
int main()
{
        printf("%d\n", ft_isdigit('l'));
        //printf("%d\n", isalpha('j'));
        return 0;
}
