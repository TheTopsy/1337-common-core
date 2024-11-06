#include<stdio.h>
#include<string.h>
size_t ft_strlen(const char *s)
{
	size_t i = 0;
	while(s[i] !='\0')
		i++;
	return i;
}
int main()
{
	printf("%ld\n", ft_strlen(""));
	printf("%ld\n", strlen(""));
	return 0;
}
