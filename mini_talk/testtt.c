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
	c = 5;
	while(i--)
	{
		if((c >> i) & 1)
		{
			printf("1");
			kill(pid, SIGUSR1);
		}
		else
		{
			printf("0");
			kill(pid, SIGUSR2);
		}
		usleep(200);
		//i++;
	}
	printf("\n");
}
