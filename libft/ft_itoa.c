#include<stdio.h>
#include<stdlib.h>

char *convertn(int n, int i, char *str)
{
	str[i] = '\0';
        i--;
        while(n > 0)
        {
                str[i] = (n % 10) + 48;
                n /= 10;
                i--;
        }
        return str;
}
char *n_iszero()
{
	char *str = malloc(2);
	if(!str)
        	return NULL;
	str[0] = '0';
	str[1] = '\0';
        return str;
}
char *n_ismin()
{
	char *str = malloc(12);
	int i = 11;
	char intmin[] = "-2147483648";
	
	str[i + 1] = '\0';
	while(i--)
		str[i] = intmin[i];
	return str;
}
char *ft_itoa(int n)
{
	char *str;
	int i = 0;
	int tmp = n;
	
	if(n == -2147483648)
		return n_ismin();
	if(n == 0)
		return n_iszero();
	while(tmp != 0)
	{
		tmp /= 10;
		i++;
	}
	if(n < 0)
	{
		i++;
		str = malloc(i + 1);
		if(!str)
			return NULL;
		str[0] = '-';
		n = -n;
	}
	else
	{
		str = malloc(i + 1);
		if(!str)
			return NULL;
	}
	return convertn(n, i, str);
}/*
int main()
{
	printf("%s", ft_itoa(-2147483648LL));
}*/
