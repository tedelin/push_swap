# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedelin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:29:25 by tedelin           #+#    #+#              #
#    Updated: 2022/12/21 19:47:45 by tedelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
MOVES_DIR = moves
SRCS = $(addprefix $(MOVES_DIR)/, push.c swap.c moves_utils.c rotate.c reverse_rotate.c) main.c
OBJS = push.o swap.o moves_utils.o rotate.o reverse_rotate.o main.o
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) push_swap.h
	$(CC) $(FLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
