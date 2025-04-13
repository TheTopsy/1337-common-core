#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int pid;
	int i = 8;
	int k = 0;
	char c;
	pid = atoi(av[1]);
	c = 0;

	while(av[2][k])
	{
		c = av[2][k];
		while(i--)
		{
			if((c >> i) & 1)
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			usleep(900);
		}
		i = 8;
		k++;
	}
}
