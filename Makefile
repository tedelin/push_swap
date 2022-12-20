# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedelin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:29:25 by tedelin           #+#    #+#              #
#    Updated: 2022/12/20 16:04:21 by tedelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
MOVES_DIR = moves
SRCS = $(MOVES_DIR)/push.c $(MOVES_DIR)/swap.c $(MOVES_DIR)/moves_utils.c $(MOVES_DIR)/rotate.c $(MOVES_DIR)/reverse_rotate.c
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
