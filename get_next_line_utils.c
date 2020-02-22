/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 11:03:19 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/27 14:06:51 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_isin(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	prep_buffer(char *buffer, char *orig)
{
	if (*buffer == '\n')
		buffer++;
	while (*buffer != '\0')
	{
		*orig = *buffer;
		buffer++;
		orig++;
	}
	*orig = '\0';
}
