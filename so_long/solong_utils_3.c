#include "solong.h"

void flood_check_utils(int *i, int *v, char flag)
{
	if(!flag)
	{
		*i = 0;
		*v = 0;
	}
	else
	{
		(*i)++;
		*v = 0;
	}
}

int flood_check(char **map, char *str, t_counts *counts)
{
	int i;
	int v;

	v = 0;
	i = 0;
	while(map[i])
	{
		while(map[i][v])
		{
			if(map[i][v] == 'P')
			{
				map[i][v] = 'F';
				check_neighbors(&map, i, v, counts);
			}
			if(map[i][v] == 'F')
			{
				map[i][v] = 'V';
				check_neighbors(&map, i, v, counts);
				flood_check_utils(&i, &v, 0);
			}
			v++;
		}
		flood_check_utils(&i, &v, 1);
	}
	return compare_counts(counts, str);
}

void set_sprites(t_mlxstuff *stuff)
{
	int height;
	int width;

	stuff->ground = mlx_xpm_file_to_image(stuff->mlx, "textures/ground.xpm", &width, &height);
	stuff->wall = mlx_xpm_file_to_image(stuff->mlx, "textures/wall.xpm", &width, &height);
	stuff->character1 = mlx_xpm_file_to_image(stuff->mlx, "textures/character1.xpm", &width, &height);
	stuff->character2 = mlx_xpm_file_to_image(stuff->mlx, "textures/character2.xpm", &width, &height);
	stuff->potion1 = mlx_xpm_file_to_image(stuff->mlx, "textures/potion1.xpm", &width, &height);
	stuff->potion2 = mlx_xpm_file_to_image(stuff->mlx, "textures/potion2.xpm", &width, &height);
	stuff->portal1 = mlx_xpm_file_to_image(stuff->mlx, "textures/portal1.xpm", &width, &height);
	stuff->portal2 = mlx_xpm_file_to_image(stuff->mlx, "textures/portal2.xpm", &width, &height);
	stuff->portal3 = mlx_xpm_file_to_image(stuff->mlx, "textures/portal3.xpm", &width, &height);
	stuff->portal4 = mlx_xpm_file_to_image(stuff->mlx, "textures/portal4.xpm", &width, &height);
}

int     close_window(void *param)
{
        t_mlxstuff *stuff = (t_mlxstuff *)param;
		free_all(stuff);
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
				    mlx_put_image_to_window(stuff->mlx, stuff->mlx_win, stuff->potion2, 16 * stuff->pot_x[i], 16 * stuff->pot_y[i]);
		}
		i++;
	}
}