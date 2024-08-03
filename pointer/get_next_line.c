#include "get_next_line.h"
#include <stdio.h> ///// REMOVE!!!


static char	*ft_read_loop(int fd, char *new)
{
	char	*buf;
	int		rsize;

	rsize = BUFFER_SIZE;
	while (rsize == BUFFER_SIZE)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return (NULL);
		rsize = read(fd, buf, BUFFER_SIZE);
		if (rsize == -1)
		{
			free(buf);
			buf = NULL;
			return(NULL);
		}
		new = ft_strjoin(new, buf);
		
		if (ft_strchr(buf, '\n'))
		{
			free(buf);
			buf = NULL;
			break;
		}
		free(buf);
		buf = NULL;
	}
	return(new);
}

static char	*ft_extract_remain(char *new, char *rem)
{
	int		a;
	char	*hold;

	rem = ft_calloc(BUFFER_SIZE, 1);

	if (!rem)
		return (NULL);
	a = 0;
	while(new[a] != '\n')
		a++;
	ft_strlcpy(rem, &new[a + 1], BUFFER_SIZE);
	new[a + 1] = 0;
	return(rem);
}

static char	*ft_handle_rem(char *rem)
{
	int		a;
	char 	*xxx;

	xxx = calloc(BUFFER_SIZE + 1, 1);
	if (ft_strchr(rem, '\n'))
	{
		a = 0;
		while(rem[a] != '\n')
			a++;
		ft_strlcpy(xxx, rem, a + 2);
		ft_strlcpy(rem, &rem[a + 1], BUFFER_SIZE);
	}
	else
	{
		ft_strlcpy(xxx, rem, BUFFER_SIZE+1);
		rem[0] = 0;
	}
	return (xxx);
}


char *get_next_line(int fd)
{
    char			*new;
	char			*tmp;
    static char		*rem;

	if (fd < 0 || BUFFER_SIZE <= 0)		
		return (NULL);

	new = ft_calloc(1, 1);
	tmp = new;
	if(rem && rem[0] != 0)
	{	
		new = ft_handle_rem(rem);
		if (ft_strchr(new, '\n')) //|| rem[0] == 0) //AQUI TA ERRADO
		{
			free(tmp);
			return(new);
		}
	}
    new = ft_read_loop(fd, new);
    if(!new || new[0] == 0)
    {
        free(new);
		free(rem);
		return (NULL);
    }
	if (ft_strchr(new, '\n'))
		rem = ft_extract_remain(new, rem);
	return (new);
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
