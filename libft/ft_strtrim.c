#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i = 0;
	while(s[i])
		i++;
	char *sub;
	if(start >= i)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return sub;
	}
	sub = (char *)malloc(len + 1);
	if(!sub)
		return NULL;
	i = 0;
	while(len--)
	{
		sub[i] = s[start++];
		i++;
	}
	sub[i] = '\0';
	return sub;
}

int	ft_check_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int i = 0;
	unsigned int j = strlen(s1);
	char	*q;
	while(s1[i] && ft_check_set(s1[i], set))
		i++;
	while (j > i && ft_check_set(s1[j - 1], set))
		j--;
	q = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!q)
		return (NULL);
	q = ft_substr(s1, i, j - i);
	return (q);
}
int main()
{
	char str[] = ".!..!bzazl!..";
	char set[] = ".!";
	printf("%s", ft_strtrim(str, set));
}
