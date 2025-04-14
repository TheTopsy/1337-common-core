#include "minitalk.h"

void handler(int sig, siginfo_t *info, void *test)
{
	int i;	 	
	static char c;
	static int bit ;
	static int oldpid;

	i = 8;
	if(info->si_pid != oldpid)
	{
		c = 0;
		bit = 0;
	}
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
	kill(info->si_pid,SIGUSR1);
	oldpid = info->si_pid;
}

int main()
{
	struct sigaction sa;
	int pid;

	pid = getpid();
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "pid is =", 8);
	ft_putnbr(pid);
	while(1)
	{
		pause();
		
	}
}
