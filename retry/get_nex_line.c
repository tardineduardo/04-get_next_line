#include "get_next_line.h"
#include <stdio.h>

static char *read_loop(int fd, char *nextline)
{
	char		buffer[BUFFER_SIZE];
	char		*temp;
	size_t		size_read;

	size_read = BUFFER_SIZE;
	while(size_read == BUFFER_SIZE)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		buffer[size_read + 1] = 0; // CHECAR ISSO!!!!
		temp = nextline;
		nextline = ft_strjoin(nextline, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return(nextline);
}

 static void	ft_extract_remain(char *nextline, char *remainder)
{
	int		a;

	a = 0;
	//maybe zero remainder?????
	while(nextline[a] != '\n')
		a++;
	ft_strlcpy(remainder, &nextline[a + 1], BUFFER_SIZE);
	nextline[a + 1] = 0;
}

char	*get_next_line(int fd)
{
	char		*nextline;
	char		*temp;
	static char	remainder[BUFFER_SIZE];

	if (fd < 0)
		return (NULL);
	nextline = ft_strdup(remainder);
	if (!nextline)
		return (NULL);
	temp = nextline;
	nextline = read_loop(fd, nextline);
	if (!nextline || nextline[0] == 0)
	{
		free(nextline);
		return (NULL);
	}
	free(temp);
	ft_extract_remain(remainder, nextline);
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


