# Default compiler
CC = cc

# Compilation flags
CFLAGS = -g
#CFLAGS = -Wall -Wextra -Werror -g


# Source files
SRCS = $(wildcard *.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = $(wildcard *.h)

# Library files
LIBS = $(wildcard *.a)

# Command to remove files
RM = rm -f

# Name of the executable, defaults to the first target
NAME = get

# Default rule to build the first argument as the executable
%: $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@$(RM) $(OBJS)

# Rule to compile object files, depends on source and header files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files
clean:
	$(RM) $(OBJS)

# Rule to fully clean the project (executable + objects)
fclean: clean
	$(RM) $(NAME)

# Rule to rebuild the project
re: fclean all

# Mark rules as phony
.PHONY: all clean fclean re