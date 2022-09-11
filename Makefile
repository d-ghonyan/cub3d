# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtiesha <mtiesha@student.42yerevan.am>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 12:15:29 by mtiesha           #+#    #+#              #
#    Updated: 2022/09/11 12:15:29 by mtiesha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =	cub3d

SRCS =	src/main.c	src/drowutils.c	src/float_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a
LINKLIB = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit -lm

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS) ${LIBFT}
	$(CC) $(CFLAGS) -o $@ $(OBJS) -I./include $(LINKLIB)
	@echo ""
	@echo "\033[1;32mcub3d Compiled"

%.o : %.c ${LIBFT} Makefile ./include/cub3d.h
	$(CC) -c $(CFLAGS) -o $@ $<
	@echo -n "\033[1;35m♥"

${LIBFT} : ./libft/Makefile ./libft/libft.h ./libft/*.c
	$(MAKE) all -C libft/
	@echo "\033[1;32mlibft Compiled"

clean :
	@$(RM) $(OBJS)
	@echo "\033[1;31mcub3d Clean"

fclean : clean
	@$(MAKE) fclean -C libft/
	@$(RM) $(NAME)
	@echo "\033[1;31mcub3d Fclean"

re : fclean all

.PHONY : all clean fclean re
