#include "solong.h"

int check_format(char *str)
{
	char ber[4] = ".ber";
	int i;
	int j;
	int k;

	k = 0;
	j = 3;
	i = 0;
	while(str[i])
		i++;
	i--;
	while(k <= j)
	{
		if(ber[j] != str[i])
			return (0);
		i--;
		j--;
	}
	i--;
	return (1);
}

int check_roof(char *str, int *l)
{
	int i;

	i = 0;
	*l = 0;
	while(str[*l])
		(*l)++;
	while(str[i] != '\n')
	{
		if(str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	invalid_chars(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] != '1' && str[i] != '0' && str[i] != 'P' && str[i] != 'C' && str[i] != 'E' && str[i] != '\n')
			{
				free(str);
				error_found(9);
			}
		i++;
	}
}
