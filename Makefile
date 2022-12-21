# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedelin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:29:25 by tedelin           #+#    #+#              #
#    Updated: 2022/12/21 18:03:18 by tedelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
MOVES_DIR = moves
SRCS = $(addprefix $(MOVES_DIR)/, push.c swap.c moves_utils.c rotate.c reverse_rotate.c) main.c
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, push.o swap.o moves_utils.o rotate.o reverse_rotate.o) main.o
LIBFT_DIR = libft
LIBFT_LIB = libft/libft.a

all: $(NAME)

$(LIBFT_LIB): libft ;

libft:
	make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS) $(LIBFT_LIB)
	$(CC) $(FLAGS) -c -o $@ $^

$(NAME): $(OBJS) $(LIBFT_LIB) push_swap.h
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
