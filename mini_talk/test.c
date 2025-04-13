#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int sig)
{
/*	if(sig == SIGUSR1)
	 	write(1 ,"1\n" , 2);
	else if (sig == SIGUSR2)
	 	write(1, "0\n", 2);
*/
	static char c = 0;
	static int bit = 0;

	if (sig == SIGUSR1)
	{
		c = (c << 1) | 1;
	}
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	bit++;
	if (bit == 8)
	{
		//printf("%d\n", c);
		//c += 48;
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
	usleep(300);
}

int main()
{
	struct sigaction sa;
	int pid;

	pid = getpid();
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("pid is = %d\n", pid);
	while(1)
	{
		pause();
		
	}
}
