#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
void ft_putendl_fd(char *s, int fd)
{
        while(*s)
        {
		write(fd, s, 1);
		s++;
        }
	write(fd, "\n", 1);
}
int main()
{
        char str[] ="Dbz";
        int fd = open("bzola.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        ft_putendl_fd(str, fd);
}
