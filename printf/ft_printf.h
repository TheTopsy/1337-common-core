/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>             +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:09:40 by adahab            #+#    #+#             */
/*   Updated: 2024/12/07 14:37:56 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);

#endif
