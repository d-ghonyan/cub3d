NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
ARCHIVE = ar -crs
SRCS = $(wildcard *.c)
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARCHIVE) $(NAME) $(OBJS) 

$(OBJS):
	$(CC) $(CFLAGS) $(SRCS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re