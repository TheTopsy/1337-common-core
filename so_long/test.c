#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct s_point
{
	int x;
	int y;
	int z;
	point *next;
} point;
typedef struct s_data 
{
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
}    t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}
int max(double a, double b)
{
	return a > b ? a : b;
}
void display_map(char *map)
{
	//parse the map and with each decimal value create a node and link it with the previous node 
	int i;
	point 
	i = 0;
	while(map[i])
	{
		if(map[i] != ' ')
		{
			//create a point, set its coords and link it to the previous point
		}
		i++;
	}
}

int main()
{
    void *mlx;
    t_data img;
    void *window;
    int x1, y1, x2, y2, i = 0;
    double stepx,stepy, dx, dy;

    mlx = mlx_init();
    img.img = mlx_new_image(mlx, 180, 180);
    window = mlx_new_window(mlx, 600, 500, "tkhrbi9");
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
    
    x1 = 112;
    y1 = 93;
    my_mlx_pixel_put(&img, x1, y1, 0xf0FF00f0);
    
    x2 = 23;
    y2 = 135;
    my_mlx_pixel_put(&img, x2, y2, 0xf0FF00f0);
    
    dx = x2 - x1;
    dy = y2 - y1;
    double step = max(abs(dx), abs(dy));
    stepx = dx / step;
    stepy = dy / step;
    
    while(i < step+1)
    {
	my_mlx_pixel_put(&img, round(x1 + i * stepx), round(y1 + i * stepy), 0x12f00022);    
	i++;
    }
    
    mlx_put_image_to_window(mlx, window, img.img, 0, 0);
    mlx_loop(mlx);
}
