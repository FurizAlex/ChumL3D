# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 12:01:54 by furizalex         #+#    #+#              #
#    Updated: 2025/12/11 16:10:22 by alechin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -no-pie -g -I$(CUB3D_HEADER_DIRECTORY)
RM = rm -rf

LIBFT = $(LIBFT_DIRECTORY)/libft.a
MLX = $(MLX_DIRECTORY)/libmlx_Linux.a

CUB3D_HEADER = $(CUB3D_HEADER_DIRECTORY)/Cub3d.h

LIBFT_DIRECTORY = libft
CUB3D_HEADER_DIRECTORY = includes
OBJECT_DIRECTORY = object
MLX_DIRECTORY = minilibx-linux

SOURCE = \
	src/main/bootloader.c					\
	src/main/cub3d.c						\
	src/main/initializing.c					\
	src/misc/controls.c						\
	src/misc/fps.c							\
	src/parsing/parse/parse_checker.c		\
	src/parsing/parse/parse_map.c			\
	src/parsing/parse/parse.c				\
	src/parsing/parse/parsing_utils.c		\
	src/parsing/texture/textures.c

OBJECTS = $(addprefix $(OBJECT_DIRECTORY)/, $(SOURCE:.c=.o))

DEFAULT := \033[1;39m
RESET := \033[0m
GREEN := \033[1;32m
YELLOW := \033[1;33m
CYAN := \033[1;36m

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@echo "$(CYAN)Compiling the wolfenstein demake...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX) -L/usr/lib -lX11 -lXext -lm -lbsd -o $(NAME)

$(OBJECT_DIRECTORY)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)\nCompiling libft files... $(RESET)"
	@make -C $(LIBFT_DIRECTORY) all --no-print-directory > /dev/null
	@echo "$(GREEN)\nSuccessfully compiled libft...$(RESET)"

clean:
	@$(RM) $(OBJECT_DIRECTORY)
	@echo "$(CYAN)\nSuccessfully cleaned all .o files...$(RESET)"

fclean: clean
	@clear
	@$(RM) $(NAME)
	@echo "$(CYAN)\nSuccessfully cleaned all makefiles files...$(RESET)"

clear:
	@clear

re: clear fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

.PHONY: all clean fclean re valgrind