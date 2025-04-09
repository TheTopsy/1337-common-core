
CC = gcc

CFLAGS = -Wall -Wextra -Werror 

MLX_FLAGS = -lmlx -L/usr/include/minilibx-linux/ -lXext -lX11

SRC = solong.c solong_utils_1.c solong_utils_2.c solong_utils_3.c solong_utils_4.c solong_utils_5.c solong_utils_6.c solong_utils_7.c get_next_line.c get_next_line_utils.c	ft_printf.c

OBJS = $(SRC:.c=.o)

NAME = so_long

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
