#include "get_next_line_bonus.h"

char	*get_next_line(int fd);
static char *ft_read_loop_heap(int fd, char *nextline);
static void	ft_extract_remain(char *nextline, char *remainder);


int main(void)
{
    int file1 = open("file1.txt", O_RDONLY);
    int file2 = open("file2.txt", O_RDONLY);
    int file3 = open("file3.txt", O_RDONLY);
    int file4 = open("file4.txt", O_RDONLY);

    char *newline;
	
	newline = get_next_line(file1);
	if (newline)
	{
		printf("file1.txt, line 1 -> %s\n",newline);
		free(newline);
	}

	newline = get_next_line(file1);
	if (newline)
	{
		printf("file1.txt, line 2 -> %s\n",newline);
		free(newline);
	}

    return (0); // Return success
}



char	*get_next_line(int fd)
{
	char		*nextline;
	static char	*remainder[_POSIX_OPEN_MAX];
	
	if (read(fd, 0, 0) == -1)
		return (NULL);
	if (!remainder[fd])
		remainder[fd] = calloc(BUFFER_SIZE, 1);
	nextline = ft_strdup(remainder[fd]);
	remainder[fd][0] = 0;
	if (!nextline)
		return (NULL);
	nextline = ft_read_loop_heap(fd, nextline);	
	if (!nextline || nextline[0] == 0)
	{
		free(remainder[fd]);
		free(nextline);
		nextline = NULL;
		return (NULL);
	}
	if (ft_strchr(nextline, '\n'))
		ft_extract_remain(nextline, remainder[fd]);
	return (nextline);
}


static char *ft_read_loop_heap(int fd, char *nextline)
{
	char		*buffer;
	char		*temp_read_loop;
	int			size_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while(!ft_strchr(nextline, '\n'))
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
			break;
	}
	free(buffer);
	buffer = NULL;
	return(nextline);
}


static void	ft_extract_remain(char *nextline, char *remainder)
{
	int		a;

	a = 0;
	while(nextline[a] != '\n' && nextline[a] != 0)
		a++;
	ft_strlcpy(remainder, &nextline[a + 1], BUFFER_SIZE);
	nextline[a + 1] = 0;
}
