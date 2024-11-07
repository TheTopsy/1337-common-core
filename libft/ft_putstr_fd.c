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