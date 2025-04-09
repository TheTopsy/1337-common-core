
#include "solong.h"

int check_boundries(char *str)
{
	int i;
	int l;

	i = 0;
	if(!check_roof(str, &l))
		return (0);
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

int check_lastchar(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	i--;
	if(str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'P' && str[i] != 'E')
		return (0);
	return (1);
}

void map_checks(char *str)
{
			if(check_lastchar(str))
			{	
				if(is_rectangular(str))
				{
					if(check_boundries(str))
						strtomap(str);
					else
					{
						free(str);
						error_found(3);
					}
				}
				else
				{
					free(str);
					error_found(4);
				}			
			}
			else
			{
				free(str);
				error_found(6);
			}
}

void fill_str(char **str, char *file_name)
{
	char *tmp;
	int fd;

	fd = open(file_name, O_RDONLY);
	if(fd == -1)
	{
		free(*str);
		error_found(5);	
	}
	tmp = get_next_line(fd);
	while(tmp)
	{
		*str = ft_strjoin(*str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
}

int main(int ac, char **av)
{
	char *str;

	if(ac > 1 && ft_strlen(av[1]) > 4)
	{
		if(check_format(av[1]))
		{
			str = malloc(1);
			str[0] = 0;
			fill_str(&str, av[1]);
			if(!check_map(str))
			{
				free(str);
				error_found(2);		
			}
			map_checks(str);
		}
		else
			error_found(1);
	}
	else
		error_found(8);
	free(str);
}
