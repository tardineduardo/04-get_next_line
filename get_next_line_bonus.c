/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:34:37 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/27 13:36:08 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_loop(int fd, char *nextline)
{
	char		*buffer;
	char		*temp_read_loop;
	int			size_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!ft_strchr(nextline, '\n'))
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[size_read] = 0;
		temp_read_loop = nextline;
		nextline = ft_strjoin(nextline, buffer);
		free(temp_read_loop);
		temp_read_loop = NULL;
		if (size_read < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (nextline);
}

static void	ft_extract_remain(char *nextline, char *remainder)
{
	int		a;

	a = 0;
	while (nextline[a] != '\n' && nextline[a] != 0)
		a++;
	ft_strlcpy(remainder, &nextline[a + 1], BUFFER_SIZE);
	nextline[a + 1] = 0;
}

char	*get_next_line(int fd)
{
	char		*nextline;
	static char	*remainder[2000];

	if (read(fd, 0, 0) == -1)
		return (NULL);
	if (!remainder[fd])
		remainder[fd] = calloc(BUFFER_SIZE, 1);
	nextline = ft_strdup(remainder[fd]);
	remainder[fd][0] = 0;
	if (!nextline)
		return (NULL);
	nextline = ft_read_loop(fd, nextline);
	if (!nextline || nextline[0] == 0)
	{
		if (nextline)
			free(nextline);
		if (remainder[fd])
			free(remainder[fd]);
		nextline = NULL;
		remainder[fd] = NULL;
		return (NULL);
	}
	if (ft_strchr(nextline, '\n'))
		ft_extract_remain(nextline, remainder[fd]);
	return (nextline);
}
