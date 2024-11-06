#include<string.h>
#include<stdlib.h>
#include<stdio.h>
char *ft_strdup(const char *s)
{
	int l = 0;
	int i = 0;
	while(s[l])
		l++;
	char *str = (char *)malloc(l + 1);
	if(!str)
		return NULL;
	while(i < l)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return str;
}
int main()
{
	char source[] = "van nestelroy 5 l 2";

	char* target = ft_strdup(source);
	//free(target);
	printf("%s", target);
	return 0;
}
