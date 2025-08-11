# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alechin <alechin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 16:39:28 by alechin           #+#    #+#              #
#    Updated: 2025/01/08 15:41:21 by alechin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_printf_utils.c ft_printf_second_utils.c

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Wextra
CC = cc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ./*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all