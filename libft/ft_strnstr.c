#include<stdio.h>
char *strnstr(const char *big, const char *little, size_t len)
{
	size_t i = 0;
	size_t j;
	if (!*little)
		return (char *)big;
	while(big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j])
		{
			j++;
		}
		if(little[j] == '\0')
                	return (char *)big + i;
		i++;
	}
	//printf("null");
	return NULL;
}
int main()
{
	const char *b = "ezaed";
	const char *l = "za";
	printf("%s\n", strnstr(b, l, 5));
}
