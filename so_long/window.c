#include "minilibx-linux/mlx.h"
#include "get_next_line.h"
#include <stdio.h>
#include <math.h>
#include <fcntl.h>

int get_height(char *str)
{
        int height;
        int i;

        i = 0;
        height = 0;
        while(str[i])
        {
                if(str[i] == '\n')
                        height++;
                i++;
        }
        return height;
}

int get_width(char *str)
{
        int width;

        width = 0;
        while(str[width] != '\n')
                width++;
        return width;
}

void allocate_map(char ***map, char *str)
{
	int columns;
	int rows;
	int i;

	rows = get_height(str);
	columns = get_width(str);
	i = 0;
	*map = malloc((rows * sizeof(char *)) + 1);
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
	while(str[i])
	{
		while(str[i] != '\n')
		{
			(*map)[k][v] = str[i];
			//printf("%c", (*map)[k][v]);
			v++;
			i++;
		}
		//printf("\n");
		v = 0;
		k++;
		i++;
	}
}

int check_char(char c, int *ccount, int *ecount)
{
	if(c == 'C')
		(*ccount)++;
	else if(c == 'E')
		(*ecount)++;
	else if(c == '1' || c == 'V')
		return (1);
	return (0);
}

void check_neighbors(char ***map, int i, int v, int *ccount, int *ecount)
{
		if((*map)[i] && (*map)[i][v + 1])
                {
                	if(!check_char((*map)[i][v + 1], ccount, ecount))
                        	(*map)[i][v + 1] = 'F';
                }
                if((*map)[i] && v > 0 && (*map)[i][v - 1])
                {
                	if(!check_char((*map)[i][v - 1], ccount, ecount))
                        	(*map)[i][v - 1] = 'F';
                }
                if((*map)[i + 1] && (*map)[i + 1][v])
                {
                	if(!check_char((*map)[i + 1][v], ccount, ecount))
				(*map)[i + 1][v] = 'F';
                }
                if(i > 0 && (*map)[i - 1] && (*map)[i - 1][v])
                {
                	if(!check_char((*map)[i - 1][v], ccount, ecount))
        	                (*map)[i - 1][v] = 'F';
                }
}

int compare_counts(int ccount, int ecount, char *str)
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
	if(c == ccount && e == ecount)
		return (1);
	return (0);
}

int flood_check(char **map, char *str)
{
	int i;
	int v;
	int ecount;
	int ccount;

	ccount = 0;
	ecount = 0;
	v = 0;
	i = 0;
	while(map[i])
	{
		if(map[i][v] == 'P')
		{
			map[i][v] = 'F';
			check_neighbors(&map, i, v, &ccount, &ecount);
			//printf("%c\n", map[i + 1][v]);
		}
		if(map[i][v] == 'F')
		{
			map[i][v] = 'V';
			check_neighbors(&map, i, v, &ccount, &ecount);
			i = 0;
			v = 0;
		}
		if(v < 7)
			v++;
		else if(i < 5)
		{
			i++;
			v = 0;
		}
		else
			break;
	}
	return compare_counts(ccount, ecount, str);
}

void strtomap(char *str)
{
        char **map;
	
        allocate_map(&map, str);
        fill_map(&map, str);
	if(flood_check(map, str))
		printf("floodcheck passed.");
}

int is_rectangular(char *map)
{
	int i;
	int lines;
	int line_length;

	i = 0;
	lines = 0;
	line_length = 0;
	while(map[line_length] != '\n')
		line_length++;
	while(map[i])
	{
		if(map[i] == '\n')
			lines++;
		i++;
	}
	if(i - lines == (lines * line_length))
		return (1);
	//printf("i = %d\nmy i = %d\n", i - lines , lines * line_length);
	return (0);
}

int check_map(char *map)
{
	int i;
	char collectable;
	char start;
	char exit;

	i = 0;
	collectable = 0;
	exit = 0;
	start = 0;
	while(map[i])
	{
		if(map[i] == 'C')
			collectable++;
		if(map[i] == 'E')
			exit++;
		if(map[i] == 'P')
			start++;
		i++;
	}
	if(collectable >= 1 && exit == 1 && start == 1)
		return (1);
	return (0);

}

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
	//printf("%c\n", str[i]);
	while(k <= j)
	{
		//printf("%c\n", ber[j]);
		if(ber[j] != str[i])
			return (0);
		i--;
		j--;
	}
	return (1);
}

int check_boundries(char *str)
{
	int i;
	int l;

	l = 0;
	i = 0;
	while(str[i] != '\n')
	{
		if(str[i] != '1')
			return (0);
		i++;
	}
	while(str[l])
		l++;
	i = 0;
	l--;
	while(str[i])
	{
		if(str[i] == '\n')
		{
			if(str[i + 1] != '1' && i < l)
				return (0);
			if(str[i - 1] != '1')
				return (0);
		}
		i++;
	}
	l--;
	while(str[l] != '\n')
	{
		if(str[l] != '1')
			return (0);
		l--;
	}
	return (1);
}



int main(int ac, char **av)
{
	void *mlx;
	void *mlx_win;
	int fd;
	char *str;
	char *tmp;

	if(ac > 1 && ft_strlen(av[1]) > 4)
	{
		if(check_format(av[1]))
		{
			printf("the file is in correct format !\n");
			fd = open(av[1], O_RDONLY);		
			tmp = get_next_line(fd);
			str = malloc(0);
			while(tmp)
			{
				str = ft_strjoin(str, tmp);
				free(tmp);
				tmp = get_next_line(fd);
			}
			if(check_map(str))
				printf("map is valid.\n");
			else
				printf("map is invalid !!\n");
			if(is_rectangular(str))
			{
				if(check_boundries(str))
				{
					printf("boundries valid.\n");
					strtomap(str);
				}
				else
					printf("boundries invalid !!\n");
				printf("map is rectangular.\n");
			}
		}
		else
			printf("the file is in wrong format !!\n");
	}
	else 
		printf("insert a file !!\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 920, "crocodile");
	
	mlx_loop(mlx);
}
