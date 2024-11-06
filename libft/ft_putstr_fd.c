#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
void ft_putstr_fd(char *s, int fd)
{
	while(*s)
	{
		write(fd, s, 1);
		s++;
	}
}
int main()
{
	char str[] ="D";
	int fd = open("bzola.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ft_putstr_fd(str, fd);
}
