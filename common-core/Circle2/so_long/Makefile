# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 18:26:25 by cde-sous          #+#    #+#              #
#    Updated: 2024/08/14 15:42:21 by cde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

ifeq ($(shell uname), Linux)
	CC := gcc
else
	CC := clang
endif

CFLAGS := -Wall -Wextra -Werror -O3

ifeq ($(shell uname), Linux)
	MLX_INCLUDES := -I/usr/include -Imlx
else
	MLX_INCLUDES := -I/opt/X11/include -Imlx
endif

MLX_DIR := mlx
MLX := $(MLX_DIR)/libmlx_$(shell uname).a

ifeq ($(shell uname), Linux)
	MLX_FLAGS := -Lmlx -lmlx -L/usr/lib/X11 -lX11 -lXext
else
	MLX_FLAGS := -Lmlx -lmlx -L/usr/lib/X11 -lX11 -lXext -framework OpenGL -framework AppKit
endif

INCLUDES := inc/so_long.h
SRC_DIR := src
SRC := main.c map.c layers.c checks.c draw.c inits.c cleanup.c
OBJ_DIR := obj
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

all: $(OBJ_DIR) $(MLX) $(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ) $(INCLUDES)
	@echo "Building $(NAME)"
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(MLX):
	@echo "Building $(MLX)"
	@make -C $(MLX_DIR)

$(LIBFT):
	@echo "Building $(LIBFT)"
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(MLX_INCLUDES) -c $< -o $@

clean:
	@echo "Removing object files of $(MLX)"
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "Removing object files of $(LIBFT)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Removing object files of $(NAME)"
	@rm -f $(OBJ)
	@rmdir $(OBJ_DIR)

fclean :clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	@echo "Removing $(LIBFT)"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
