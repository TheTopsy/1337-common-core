/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topsy <adahab@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:10:05 by adahab            #+#    #+#             */
/*   Updated: 2025/04/09 08:07:51 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_putstr(char *str, char c, char flag)
{
	int	count;

	count = 0;
	if (flag)
	{
		write(1, &c, 1);
		count++;
	}
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count++;
		ft_putstr("", '-', 1);
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		count++;
		ft_putstr("", n + 48, 1);
	}
	return (count);
}

int	ft_puthex(unsigned long n, char c, char print0x, char flag)
{
	char	*hex;
	int		count;

	count = 0;
	if (n == 0 && flag)
	{
		count += ft_putstr("(nil)", 0, 0);
		return (count);
	}
	if (print0x)
		count += ft_putstr("0x", 0, 0);
	if (c == 'x' || c == 'p')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_puthex(n / 16, c, 0, 0);
	}
	count++;
	ft_putstr("", hex[n % 16], 1);
	return (count);
}

int	printf_check_format(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putstr("", va_arg(args, int), 1);
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *), 0, 0);
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(args, unsigned int), c, 0, 0);
	else if (c == 'p')
		count += ft_puthex((unsigned long)va_arg(args, unsigned int *), 'p', 1,
				1);
	else if (c == '%')
		count += ft_putstr("", '%', 1);
	else if (c == 'u')
		count += ft_putnbr(va_arg(args, unsigned int));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		while (*s && *s != '%')
		{
			write(1, s, 1);
			s++;
			count++;
		}
		if (*s && *s == '%')
		{
			s++;
			count += printf_check_format(args, *s);
			s++;
		}
	}
	va_end(args);
	return (count);
}
