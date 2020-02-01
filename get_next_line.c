/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 11:03:17 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/18 13:39:47 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>

char	*ft_realloc(char *src, int len)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * len + BUFFER_SIZE);
	while (i < len)
	{
		res[i] = src[i];
		i++;
	}
	if (src)
		free(src);
	return (res);
}

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		i;
	char	*resptr;

	i = 0;
	while (dest[i] != '\0')
		i++;
	resptr = dest + i;
	i = 0;
	while (i < nb)
	{
		*resptr = *src;
		resptr++;
		src++;
		i++;
	}
	*resptr = '\0';
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer;
	int			ret;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer || !line || fd == -1)
		return (-1);
	if(!*line)
        *line = malloc(100 * sizeof(char));

    /* Blank out the line */
    *line[0] = '\0';
	ret = read(fd, buffer, BUFFER_SIZE);
    while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
        ft_strncat(*line, buffer, BUFFER_SIZE);
        if(buffer[0] == '\n')
            break;
    }
	return (0);
}
