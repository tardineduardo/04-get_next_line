#include "get_next_line.h"
#include <stdio.h>

static char *read_loop(int fd, char *nextline)
{
	char		buffer[BUFFER_SIZE+1];
	char		*temp_read_loop;
	size_t		size_read;

	while(!ft_strchr(nextline, '\n'))
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		buffer[size_read] = 0; // CHECAR ISSO!!!!
		temp_read_loop = nextline;
		nextline = ft_strjoin(nextline, buffer);
		free(temp_read_loop);	
		if (size_read < BUFFER_SIZE)
			break;
	}
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

char	*get_next_line(int fd)
{
	char		*nextline;
	static char	remainder[BUFFER_SIZE];

	if (fd < 0)
		return (NULL);
	nextline = ft_strdup(remainder);
	remainder[0] = 0;
	if (!nextline)
		return (NULL);
	nextline = read_loop(fd, nextline);
	if (!nextline || nextline[0] == 0)
	{
		free(nextline);
		return (NULL);
	}
	if (ft_strchr(nextline, '\n'))
		ft_extract_remain(nextline, remainder);
	return (nextline);
}


int main(void)
{
    int file = open("test1", O_RDONLY); // Open a file for reading
    int a = 0; // Counter for lines
    int b = 1; // Line number for printing
    char *newline; // Pointer to store the line read
	char *tmp;
	newline = malloc (1*1);
	tmp = newline;
    while(newline) 
    {
        newline = get_next_line(file); // Get the next line from the file
        if (newline == NULL) // If NULL is returned (EOF or error)
		{
			break; // Exit the loop
		}
        printf("newline %d -> %s", b, newline); // Print the line
		free(newline); // Free the line after printing to prevent memory leaks

        a++; // Increment line counter
        b++; // Increment line number
    }
	free(tmp); // Free the line after printing to prevent memory leaks
	tmp = NULL;
    return (0); // Return success
}


