#include "/usr/include/minilibx-linux/mlx.h"
//#include "/mnt/c/Users/azert/Desktop/fdf/minilibx-linux/mlx.h"
#include "get_next_line.h"
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <string.h>
typedef struct s_mlxstuff
{
    void *mlx;
    void *mlx_win;
    void *ground;
    void *wall;
    void *character1;
    void *character2;
    void *potion1;
    void *potion2;
    void *portal1;
    void *portal2;
	void *portal3;
	void *portal4;
	int char_x;
	int char_y;
	int por_x;
	int por_y;
	int *pot_x;
	int *pot_y;
	int potcount;
	int currentc;
	int frame;
	int moves;
	char *str;
	char **map;
	char char_on_exit;
} t_mlxstuff;

void free_images(t_mlxstuff *stuff)
{
	int i = 0;
	mlx_destroy_image(stuff->mlx, stuff->character1);
	mlx_destroy_image(stuff->mlx, stuff->character2);
	mlx_destroy_image(stuff->mlx, stuff->potion1);
	mlx_destroy_image(stuff->mlx, stuff->potion2);
	mlx_destroy_image(stuff->mlx, stuff->portal1);
	mlx_destroy_image(stuff->mlx, stuff->portal2);
	mlx_destroy_image(stuff->mlx, stuff->portal3);
	mlx_destroy_image(stuff->mlx, stuff->portal4);
	mlx_destroy_image(stuff->mlx, stuff->ground);
	mlx_destroy_image(stuff->mlx, stuff->wall);
	free(stuff->pot_x);
	free(stuff->pot_y);
	while(stuff->map[i])
	{
		free(stuff->map[i]);
		i++;
	}
	free(stuff->map);
	free(stuff->str);
	mlx_destroy_window(stuff->mlx, stuff->mlx_win);
	mlx_destroy_display(stuff->mlx);
	free(stuff->mlx);
	free(stuff);
}

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
	height++;
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
	/*while(str[i])
	{
		printf("%d\n", str[i]);
		while(str[i] && str[i] != '\n')
		{
			printf("%d\n", str[i]);
			(*map)[k][v] = str[i];
			//printf("%c", (*map)[k][v]);
			v++;
			i++;
		}
		//printf("\n");
		v = 0;
		k++;
		i++;
	}*/

	while(k < get_height(str))
	{
		while(v < get_width(str))
		{
			(*map)[k][v] = str[i];
			printf("%c", (*map)[k][v]);
			v++;
			i++;
		}
		printf("\n");
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

/*void check_neighbors(char **map, int i, int v, int *ccount, int *ecount)
{
                if(map[i] && map[i][v + 1])
                {
                        if(!check_char(map[i][v + 1], ccount, ecount))
                                map[i][v + 1] = 'F';
                }
                if(map[i] && v > 0 && map[i][v - 1])
                {
                        if(!check_char(map[i][v - 1], ccount, ecount))
                                map[i][v - 1] = 'F';
                }
                if(map[i + 1] && map[i + 1][v])
                {
                        if(!check_char(map[i + 1][v], ccount, ecount))
                                map[i + 1][v] = 'F';
                }
                if(i > 0 && map[i - 1] && map[i - 1][v])
                {
                        if(!check_char(map[i - 1][v], ccount, ecount))
                                map[i - 1][v] = 'F';
                }
}*/

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
	//printf("my ecount = %d ecount = %d my ccount = %d ccount = %d\n", ecount, e, ccount, c);
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
		}
		if(map[i][v] == 'F')
		{
			map[i][v] = 'V';
			check_neighbors(&map, i, v, &ccount, &ecount);
			i = 0;
			v = 0;
		}
		if(v < get_width(str))
		v++;
		else if(i < get_height(str))
		{
			i++;
			v = 0;
		}
		else
			break;
	}
	return compare_counts(ccount, ecount, str);
}

void set_sprites(t_mlxstuff *stuff)
{
	int height;
	int width;

	stuff->ground = mlx_xpm_file_to_image(stuff->mlx, "../Assets/ground.xpm", &width, &height);
	stuff->wall = mlx_xpm_file_to_image(stuff->mlx, "../Assets/wall.xpm", &width, &height);
	stuff->character1 = mlx_xpm_file_to_image(stuff->mlx, "../Assets/character1.xpm", &width, &height);
	stuff->character2 = mlx_xpm_file_to_image(stuff->mlx, "../Assets/character2.xpm", &width, &height);
	stuff->potion1 = mlx_xpm_file_to_image(stuff->mlx, "../Assets/potion1.xpm", &width, &height);
	stuff->potion2 = mlx_xpm_file_to_image(stuff->mlx, "../Assets/potion2.xpm", &width, &height);
	stuff->portal1 = mlx_xpm_file_to_image(stuff->mlx, "../Assets/portal1.xpm", &width, &height);
	stuff->portal2 = mlx_xpm_file_to_image(stuff->mlx, "../Assets/portal2.xpm", &width, &height);
	stuff->portal3 = mlx_xpm_file_to_image(stuff->mlx, "../Assets/portal3.xpm", &width, &height);
	stuff->portal4 = mlx_xpm_file_to_image(stuff->mlx, "../Assets/portal4.xpm", &width, &height);
}

int     close_window(void *param)
{
        t_mlxstuff *stuff = (t_mlxstuff *)param;
		free_images(stuff);
        exit(0);
        return (0);
}

void animate_potions(t_mlxstuff *stuff)
{
	int i;

	i = 0;
	while(i < stuff->potcount)
	{
		if (stuff->frame % 10000 < 5000 && stuff->pot_x[i] != -10)
		{
        	        mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->potion1, 16 * stuff->pot_x[i], 16 * stuff->pot_y[i]);
		}
		else if(stuff->frame % 10000 >= 5000 && stuff->pot_x[i] != -10)
        {
					//printf("test%d\n", stuff->frame);
				    mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->potion2, 16 * stuff->pot_x[i], 16 * stuff->pot_y[i]);
		}
		i++;
	}
}

int animate(t_mlxstuff *stuff)
{
	stuff->frame++;
	if (stuff->frame % 10000 < 5000)
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->character1, 16 * stuff->char_x, 16 * stuff->char_y);
	else	
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->character2, 16 * stuff->char_x, 16 * stuff->char_y);
    if (stuff->frame % 10000 < 5000)
                mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->portal1, 16 * stuff->por_x, 16 * stuff->por_y);
    else if(stuff->frame % 10000 >= 5000)
                mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->portal2, 16 * stuff->por_x, 16 * stuff->por_y);
	if (stuff->frame % 10000 < 5000 && stuff->por_x == stuff->char_x && stuff->por_y == stuff->char_y)
	{
                mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->portal3, 16 * stuff->por_x, 16 * stuff->por_y);
		if(stuff->currentc == stuff->potcount)
			close_window(stuff);
	}
	else if(stuff->frame % 10000 >= 5000 && stuff->por_x == stuff->char_x && stuff->por_y == stuff->char_y)
                mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->portal4, 16 * stuff->por_x, 16 * stuff->por_y);
	animate_potions(stuff);
	return (0);
}

void collect_potion(t_mlxstuff *stuff, int i)
{
	stuff->pot_x[i] = -10;
	stuff->currentc++;
}

void left_right(t_mlxstuff *stuff, char dir)
{
	int i;

	i = 0;

	if(dir == 6)
	{
		while(i < stuff->potcount)
		{
			if(stuff->pot_x[i] == stuff->char_x + 1 && stuff->pot_y[i] == stuff->char_y)
				collect_potion(stuff, i);
			i++;
		}
	}
	else if(dir == 4)
	{
		while(i < stuff->potcount)
		{
			if(stuff->pot_x[i] == stuff->char_x - 1 && stuff->pot_y[i] == stuff->char_y)
				collect_potion(stuff, i);
			i++;
		}
	}
}
void interact(t_mlxstuff *stuff, char dir)
{
		int i;

        i = 0;
        left_right(stuff, dir);
		if(dir == 8)
        {
        	while(i < stuff->potcount)
            {
                if(stuff->pot_x[i] == stuff->char_x && stuff->pot_y[i] == stuff->char_y -1)
				collect_potion(stuff, i);
                i++;
            }
        }
        else if(dir == 2)
        {
             while(i < stuff->potcount)
            {
				if(stuff->pot_x[i] == stuff->char_x && stuff->pot_y[i] == stuff->char_y + 1)
				collect_potion(stuff, i);
                i++;
            }
        }
}

void up_down(t_mlxstuff *stuff, char dir)
{
	if(dir == 8 && stuff->char_y > 0 && stuff->map[stuff->char_y - 1][stuff->char_x] != '1')
	{
		interact(stuff, dir);
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->ground, 16 * stuff->char_x, 16 * stuff->char_y);
		stuff->char_y--;
		//printf("moves : %d\n", ++stuff->moves);
	}
	else if(dir == 2 && stuff->char_y < get_height(stuff->str) && stuff->map[stuff->char_y + 1][stuff->char_x] != '1')
	{
		interact(stuff, dir);
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->ground, 16 * stuff->char_x, 16 * stuff->char_y);
		stuff->char_y++;
		//printf("moves : %d\n", ++stuff->moves);
	}
}
//REAL PRINTF IS USED HERE
void check_next_tile(t_mlxstuff *stuff, char dir)
{
	if(dir == 6 && stuff->char_x < get_width(stuff->str) && stuff->map[stuff->char_y][stuff->char_x + 1] != '1')
	{
		interact(stuff, dir);
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->ground, 16 * stuff->char_x, 16 * stuff->char_y);
		stuff->char_x++;
		//printf("moves : %d\n", ++stuff->moves);
	}
	else if(dir == 4 && stuff->char_x > 0 && stuff->map[stuff->char_y][stuff->char_x - 1] != '1')
	{
		interact(stuff, dir);
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->ground, 16 * stuff->char_x, 16 * stuff->char_y);
		stuff->char_x--;
		//printf("moves : %d\n", ++stuff->moves);
	}
	else
		up_down(stuff, dir);
}

int	key_hook(int keycode, t_mlxstuff *stuff)
{
	if(keycode == 65363)
		check_next_tile(stuff, 6);
	if(keycode == 65361)
		check_next_tile(stuff, 4);
	if(keycode == 65364)
		check_next_tile(stuff, 2);
	if(keycode == 65362)
		check_next_tile(stuff, 8);
	if(keycode == 65307)
		close_window(stuff);
	return (0);
}

void initialize_stuff(t_mlxstuff **stuff, int collectables, char *str, int *i, int *v, int *p)
{
	*p = 0;
	*i = 0;
	*v = 0;
	(*stuff) = malloc(sizeof(t_mlxstuff));
	if(!(*stuff))
		exit(EXIT_FAILURE);
	(*stuff)->currentc = 0;
	(*stuff)->mlx = mlx_init();
	(*stuff)->mlx_win = mlx_new_window((*stuff)->mlx, get_width(str) *16 , get_height(str) *16, "game");
	set_sprites((*stuff));
	(*stuff)->pot_x = malloc(collectables * sizeof(int));
	(*stuff)->pot_y = malloc(collectables * sizeof(int));
	(*stuff)->potcount = collectables;
	(*stuff)->str = str;
	
}

int display_tile(t_mlxstuff *stuff, char **map, int i, int v, int p)
{
	if(map[i][v] == '0')
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->ground, 16 * v, 16 * i);
	else if(map[i][v] == '1')
		mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->wall, 16 * v, 16 * i);
	else if(map[i][v] == 'P')
	{
		stuff->char_x = v;
		stuff->char_y = i;
	}
	else if(map[i][v] == 'E')
	{
		stuff->por_x = v;
		stuff->por_y = i;
	}
	else if(map[i][v] == 'C')
	{
		stuff->pot_x[p] = v;
		stuff->pot_y[p] = i;
		return (1);
	}
	return (0);
}
void display_map(char **map, int collectables, char *str)
{
	t_mlxstuff *stuff;
	int i;
	int v;
	int p;

	initialize_stuff(&stuff, collectables, str, &i, &v, &p);
	stuff->map = map;
	while(map[i])
	{
		while(map[i][v])
		{	
			if(display_tile(stuff, map, i, v, p))
				p++;
			v++;
		}
		v = 0;
		i++;
	}
	stuff->frame = 0;
	mlx_hook(stuff->mlx_win, 17, 0, close_window, stuff);
	mlx_loop_hook(stuff->mlx, animate, stuff);
	mlx_key_hook(stuff->mlx_win, key_hook, stuff);
	mlx_loop(stuff->mlx);
}

int countc(char *str)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while(str[i])
	{
		if(str[i] == 'C')
			c++;
		i++;
	}
	return c;
}

void strtomap(char *str)
{
        char **map = NULL;

        allocate_map(&map, str);
        fill_map(&map, str);
	if(flood_check(map, str))
	{
		printf("floodcheck passed.\n");
		fill_map(&map, str);
		display_map(map, countc(str), str);
	}
	else 
		printf("floodcheck didnt pass !!\n");
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
	{
		// printf("l = %c\n", map[line_length]);
		line_length++;
	}
		//line_length--;
	//DEBUG
	//line_length = 28;
	//printf("line length = %d\n", line_length);
	while(map[i])
	{
		if(map[i] == '\n')
			lines++;
		i++;
	}
	lines++;
	i++;
	// printf("number of lines = %d\n", lines);
	// printf("i = %d\n", i);
	if((i - lines) == (lines * line_length))
		return (1);
	return (0);
}

int check_map(char *map)
{
	int i;
	int collectable;
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
	i -= 2;
	if(str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'P' && str[i] != 'E')
		return (0);
	return (1);
}
//handle freeing when error happens
//handle / in front of the of the file

/*void error_found(char type)
{

	exit(0);
}*/

int main(int ac, char **av)
{
	int fd;
	char *str;
	char *tmp;
	//t_mlxstuff *stuff;

	if(ac > 1 && ft_strlen(av[1]) > 4)
	{
		if(check_format(av[1]))
		{
			printf("the file is in correct format !\n");
			fd = open(av[1], O_RDONLY);		
			tmp = get_next_line(fd);
			str = malloc(1);
			str[0] = 0;
			while(tmp)
			{
				str = ft_strjoin(str, tmp);
				free(tmp);
				tmp = get_next_line(fd);
			}
			if(check_map(str))
				printf("map is valid.\n");
			else
			{
				printf("map is invalid !!\n");
				return (0);
			}
			if(check_lastchar(str))
			{	
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
				else 
					printf("map not rectangular\n");
			}
			else
				printf("found invalid characters in the end !!\n");
		}
		else
			printf("the file is in wrong format !!\n");
	}
	else 
		printf("insert a file !!\n");
	free(str);
	free(tmp);
}
