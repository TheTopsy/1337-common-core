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
		c = c | (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		printf("%d\n", c);
		//write(1, &c, 1);
		c = 0;
		bit = 0;
	}
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
	while(1)
	{
		printf("pid is = %d\n", pid);
		pause();
		
	}
}
