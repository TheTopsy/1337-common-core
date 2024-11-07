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
