# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjada <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 18:00:58 by anjada            #+#    #+#              #
#    Updated: 2019/11/06 20:23:30 by anjada           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

PATH_LIBFT = libft

SRC = main.c fillit.c validation.c writer.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(PATH_LIBFT)/libft.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L $(PATH_LIBFT) -lft

$(PATH_LIBFT)/libft.a:
	make -C $(PATH_LIBFT)

%.o: %.c fillit.h
	$(CC) $(CFLAGS) -c $< -I $(PATH_LIBFT)

clean:
	rm -f $(OBJ)
	make -C $(PATH_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
