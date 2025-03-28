/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahab <adahab@student.1337.ma>             +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:08:03 by adahab            #+#    #+#             */
/*   Updated: 2025/03/23 02:52:04 by adahab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#if BUFFER_SIZE < 0
#undef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif

// read buffersize lines until newline is found
// store them in savedline
// extract line from savedline
// store it in output
// move savedline to point to the nextline

char	*read_line(int fd, char *savedline)
{
	char	*cread;
	ssize_t	count;

	cread = malloc(BUFFER_SIZE + 1);
	if (!cread)
		return (NULL);
	count = read(fd, cread, BUFFER_SIZE);
	while (count > 0)
	{
		cread[count] = '\0';
		if (!savedline)
			savedline = ft_strdup("");
		savedline = ft_strjoin(savedline, cread);
		if (!savedline)
			return (free(cread), NULL);
		if (ft_strchr(cread, '\n'))
			break ;
		count = read(fd, cread, BUFFER_SIZE);
	}
	free(cread);
	if (count < 0)
		return (free(savedline), NULL);
	return (savedline);
}

char	*extract_line(char *savedline)
{
	char	*output;
	int		i;

	i = 0;
	if (!savedline)
		return (NULL);
	while (savedline[i] && savedline[i] != '\n')
		i++;
	if (savedline[i] == '\n')
		i++;
	output = ft_strndup(savedline, i);
	if (!output)
		return (free(savedline), NULL);
	return (output);
}

char	*move_to_next_line(char *savedline)
{
	char	*tmp;
	char	*nextline;

	nextline = ft_strchr(savedline, '\n');
	if (!nextline)
		return (free(savedline), NULL);
	tmp = ft_strndup(nextline + 1, ft_strlen(nextline + 1));
	if (!tmp)
		return (free(savedline), NULL);
	free(savedline);
	savedline = tmp;
	return (savedline);
}

char	*get_next_line(int fd)
{
	static char	*savedline;
	char		*output;
	
	if(BUFFER_SIZE == 0)
		return NULL;
	savedline = read_line(fd, savedline);
	if (!savedline || !*savedline)
		return (free(savedline), savedline = NULL, NULL);
	output = extract_line(savedline);
	savedline = move_to_next_line(savedline);
	return (output);
}

/*int main()
{
	int fd = open("fff.txt", O_RDONLY);
	//int n = 3;

	char	*line;
	line = get_next_line(fd);
	//printf("%s", line);
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}*/
