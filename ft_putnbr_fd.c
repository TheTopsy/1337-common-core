#include<unistd.h>
#include<fcntl.h>
void	ft_putchar_fd(char c, int fd) 
{
	write(fd, &c, 1);
}

void ft_putnbr_fd(int n, int fd)
{

	if (n < 0)
       	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10) 
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
	       	ft_putchar_fd(n + 48, fd);
}
int main()
{
	int fd = open("bzola.txt", O_WRONLY | O_CREAT |O_TRUNC, 0666);
	ft_putnbr_fd(2147483648, fd);
}
