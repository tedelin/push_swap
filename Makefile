# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedelin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:29:25 by tedelin           #+#    #+#              #
#    Updated: 2023/01/12 17:00:35 by tedelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER_FILE = src/push_swap.h
SRC_DIR = src
OBJ_DIR = obj
SRC = $(addprefix $(SRC_DIR)/, 3_5.c lis.c main.c stack_utils.c push.c reverse_rotate.c rotate.c sort.c swap.c best.c utils.c check_args.c)
OBJS = $(addprefix $(OBJ_DIR)/, 3_5.o lis.o main.o stack_utils.o push.o reverse_rotate.o rotate.o sort.o swap.o best.o utils.o check_args.o)

LIBFT_DIR = libft
LIBFT_LIB = libft/libft.a

all: $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) -o $@ $^

obj/%.o: src/%.c $(HEADER_FILE)
	@mkdir -p $(dir $@)
	$(CC) -c $(FLAGS) -o $@ $<

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
