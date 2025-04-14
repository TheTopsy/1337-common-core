/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:52 by adahab            #+#    #+#             */
/*   Updated: 2025/04/14 16:46:05 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	handler(int sig, siginfo_t *info, void *test);
void	update_g(int sig);
void	send_bit(int c, pid_t pid);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);

#endif
