/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:44:59 by adahab            #+#    #+#             */
/*   Updated: 2025/04/14 16:49:19 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_bitsent;

void	update_g(int sig)
{
	(void)sig;
	g_bitsent = 1;
}

void	error_found(void)
{
	write(2, "error pid", 9);
	exit(1);
}

void	send_bit(int c, pid_t pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		g_bitsent = 0;
		if (((c >> i) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_found();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_found();
		}
		while (!g_bitsent)
		{
			if (kill(pid, 0) == -1)
				exit(0);
		}
		usleep(100);
	}
}

int	isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(1, "invalid pid\n", 12);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3)
	{
		write(1, "incorrect input !! try [exe] [pid] [msg]\n", 41);
		return (1);
	}
	signal(SIGUSR1, update_g);
	isnum(av[1]);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "invalid pid\n", 12);
		return (1);
	}
	i = 0;
	while (av[2][i])
	{
		send_bit(av[2][i], pid);
		i++;
	}
	return (0);
}
