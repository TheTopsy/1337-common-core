#include "solong.h"

void allocate_map(char ***map, char *str)
{
	int columns;
	int rows;
	int i;

	rows = get_height(str);
	columns = get_width(str);
	i = 0;
	*map = malloc((rows + 1) * sizeof(char *));
	if(!*map)
		exit(EXIT_FAILURE);
	(*map)[rows] = '\0';
	while(i < rows)
	{
		(*map)[i] = malloc(columns + 1);
		if(!(*map)[i])
			exit(EXIT_FAILURE);
		(*map)[i][columns] = '\0';
		i++;
	}
}

void fill_map(char ***map, char *str)
{
	int i;
	int k;
	int v;
	
	v = 0;
	i = 0;
	k = 0;
	while(k < get_height(str))
	{
		while(v < get_width(str))
		{
			(*map)[k][v] = str[i];
			v++;
			i++;
		}
		v = 0;
		k++;
		i++;
	}
}

int check_char(char c, t_counts *counts)
{
	if(c == 'C')
		counts->ccount++;
	else if(c == 'E')
		counts->ecount++;
	else if(c == '1' || c == 'V')
		return (1);
	return (0);
}

void check_neighbors(char ***map, int i, int v, t_counts *counts)
{
		if((*map)[i] && (*map)[i][v + 1])
                {
                	if(!check_char((*map)[i][v + 1], counts))
                        	(*map)[i][v + 1] = 'F';
                }
                if((*map)[i] && v > 0 && (*map)[i][v - 1])
                {
                	if(!check_char((*map)[i][v - 1], counts))
                        	(*map)[i][v - 1] = 'F';
                }
                if((*map)[i + 1] && (*map)[i + 1][v])
                {
                	if(!check_char((*map)[i + 1][v], counts))
				(*map)[i + 1][v] = 'F';
                }
                if(i > 0 && (*map)[i - 1] && (*map)[i - 1][v])
                {
                	if(!check_char((*map)[i - 1][v], counts))
        	                (*map)[i - 1][v] = 'F';
                }
}

int compare_counts(t_counts *counts, char *str)
{
	int i;
	int c;
	int e;

	e = 0;
	c = 0;
	i = 0;
	while(str[i])
	{
		if(str[i] == 'C')
			c++;
		else if(str[i] == 'E')
			e++;
		i++;
	}
	if(c == counts->ccount && e == counts->ecount)
		return (1);
	return (0);
}