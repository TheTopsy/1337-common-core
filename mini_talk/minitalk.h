#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void handler(int sig, siginfo_t *info, void *test);
void update_g(int sig);
void send_bit(int  c, pid_t pid);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int	ft_atoi(const char *str);

#endif