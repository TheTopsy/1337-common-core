# ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	int i;
	int p;
	int v;
} t_mlxstuff;

typedef struct s_counts
{
	int ccount;
	int ecount;
} t_counts;

int		ft_strlen(char *s);
char	*ft_strndup(char *str, size_t n);
char	*ft_strchr(const char *s, int chr);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);

char	*get_next_line(int fd);
char	*move_to_next_line(char *savedline);
char	*read_line(int fd, char *savedline);

void error_found(char type);
void free_images(t_mlxstuff *stuff);
void free_all(t_mlxstuff *stuff);
int get_height(char *str);
int get_width(char *str);
void allocate_map(char ***map, char *str);
void fill_map(char ***map, char *str);
int check_char(char c, t_counts *counts);
void check_neighbors(char ***map, int i, int v, t_counts *counts);
int compare_counts(t_counts *counts, char *str);
void flood_check_utils(int *i, int *v, char flag);
int flood_check(char **map, char *str, t_counts *counts);
void set_sprites(t_mlxstuff *stuff);
int     close_window(void *param);
void animate_potions(t_mlxstuff *stuff);
int animate(t_mlxstuff *stuff);
void collect_potion(t_mlxstuff *stuff, int i);
void left_right(t_mlxstuff *stuff, char dir);
void interact(t_mlxstuff *stuff, char dir);
void up_down(t_mlxstuff *stuff, char dir);
void check_next_tile(t_mlxstuff *stuff, char dir);
int	key_hook(int keycode, t_mlxstuff *stuff);
void initialize_stuff(t_mlxstuff **stuff, int collectables, char *str);
int display_tile(t_mlxstuff *stuff, char **map);
void display_map(char **map, int collectables, char *str);
int countc(char *str);
void init_counts(t_counts *counts);
void strtomap(char *str);
int is_rectangular(char *map);
int check_map(char *map);
int check_format(char *str);
int check_roof(char *str, int *l);
int check_boundries(char *str);
int check_lastchar(char *str);
void map_checks(char *str);
void fill_str(char **str, char *file_name);


int	ft_putstr(char *str, char c, char flag);
int	ft_putnbr(long n);
int	ft_puthex(unsigned long n, char c, char print0x, char flag);
int	check_format(va_list args, char c);
int	ft_printf(const char *s, ...);