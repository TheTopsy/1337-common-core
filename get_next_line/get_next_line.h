/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>             +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:08:40 by adahab            #+#    #+#             */
/*   Updated: 2024/12/31 00:08:55 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *s);
char	*ft_strndup(char *str, size_t n);
char	*ft_strchr(const char *s, int chr);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);

char	*get_next_line(int fd);
char	*move_to_next_line(char *savedline);
char	*read_line(int fd, char *savedline);

#endif
