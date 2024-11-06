#include<stdio.h>
char *ft_strchr(const char *str, int c)
{
	int i = 0;
	int l = 0;
	while(str[l])
	{
		l++;	
	}
	while(str[i] != c && str[i])
	{
		i++;
	}
	if(i == l)
		return NULL;
	return (char *)str + i;
}
int main()
{
	char *p = "baysal";
	printf("%s", ft_strchr(p, ' '));
	//printf(strchr("", ))
	return 0;
}
