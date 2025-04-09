#include "solong.h"

void error_found(char type)
{
	ft_printf("Error\n");
	if(type == 1)
		ft_printf("invalid file, wrong format !\n");
	else if(type == 2)
		ft_printf("the map doesnt have all the components or exit/spawn is duplicated !\n");
	else if(type == 3)
		ft_printf("the map is not bounded by walls !\n");
	else if(type == 4)
		ft_printf("the map is not rectangular !\n");
	else if(type == 5)
		ft_printf("file doesnt exist !\n");
	else if(type == 6)
		ft_printf("found unvalid characters or newline(s) after the last character of the map !\n");
	else if(type == 7)
		ft_printf("soft locked ! (make sure there is a valid path to the exit and the collectables)\n");
	else if(type == 8)
		ft_printf("insert a file !\n");
	exit(0);
}
void free_images(t_mlxstuff *stuff)
{
	if(stuff->character1)
		mlx_destroy_image(stuff->mlx, stuff->character1);
	if(stuff->character2)
		mlx_destroy_image(stuff->mlx, stuff->character2);
	if(stuff->potion1)
		mlx_destroy_image(stuff->mlx, stuff->potion1);
	if(stuff->potion2)
		mlx_destroy_image(stuff->mlx, stuff->potion2);
	if(stuff->portal1)
		mlx_destroy_image(stuff->mlx, stuff->portal1);
	if(stuff->portal2)
		mlx_destroy_image(stuff->mlx, stuff->portal2);
	if(stuff->portal3)
		mlx_destroy_image(stuff->mlx, stuff->portal3);
	if(stuff->portal4)
		mlx_destroy_image(stuff->mlx, stuff->portal4);
	if(stuff->ground)
		mlx_destroy_image(stuff->mlx, stuff->ground);
	if(stuff->wall)
		mlx_destroy_image(stuff->mlx, stuff->wall);
	if(stuff->pot_x)
		free(stuff->pot_x);
	if(stuff->pot_y)
		free(stuff->pot_y);
}
void free_all(t_mlxstuff *stuff)
{
	int i;

	i = 0;
	free_images(stuff);
	while(stuff->map[i])
	{
		free(stuff->map[i]);
		i++;
	}
	if(stuff->map)
		free(stuff->map);
	if(stuff->str)
		free(stuff->str);
	
		
	if(stuff->mlx)
	{
		if(stuff->mlx_win)
			mlx_destroy_window(stuff->mlx, stuff->mlx_win);
		mlx_destroy_display(stuff->mlx);
		free(stuff->mlx);
	}
	if(stuff)
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