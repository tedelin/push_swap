# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedelin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:29:25 by tedelin           #+#    #+#              #
#    Updated: 2022/12/14 17:07:48 by tedelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = moves/moves.c moves/moves2.c moves/moves3.c main.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) push_swap.h libft.h
	$(CC) $(FLAGS) -o $(NAME) $(NAME) -c $(SRCS) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
