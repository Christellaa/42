# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 18:26:25 by cde-sous          #+#    #+#              #
#    Updated: 2024/09/07 15:25:45 by cde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
NAMEB := so_long_bonus

ifeq ($(shell uname), Linux)
	CC := gcc
else
	CC := clang
endif

CFLAGS := -Wall -Wextra -Werror -O3 -g3

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
	MLX_FLAGS := -Lmlx -lmlx -L/usr/lib/X11 -lX11 -lXext -framework OpenGL \
	-framework AppKit
endif

INCLUDES := inc/so_long.h inc/colors.h inc/keys.h inc/imgs.h
INCLUDES_B := inc_bonus/so_long_bonus.h inc_bonus/colors_bonus.h \
			inc_bonus/keys_bonus.h inc_bonus/imgs_bonus.h
SRC_DIR := src
SRC := so_long.c inits.c map.c draw.c checks.c reachability.c interactions.c \
		cleanup.c utils.c
SRC_DIR_B := src_bonus
SRC_B := so_long_bonus.c inits_bonus.c map_bonus.c draw_bonus.c checks_bonus.c \
		reachability_bonus.c interactions_bonus.c moves_bonus.c cleanup_bonus.c \
		so_long_utils_bonus.c
OBJ_DIR := obj
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_B := $(SRC_B:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

all: $(OBJ_DIR) $(MLX) $(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(INCLUDES)
	@echo "Building $(NAME)"
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(NAMEB): $(OBJ_B) $(INCLUDES)
	@echo "Building $(NAMEB)"
	@$(CC) $(CFLAGS) $(OBJ_B) $(MLX_FLAGS) $(LIBFT) -o $(NAMEB)

$(MLX):
	@echo "Building $(MLX)"
	@make -C $(MLX_DIR)

$(LIBFT):
	@echo "Building $(LIBFT)"
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(MLX_INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR_B)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(MLX_INCLUDES) -c $< -o $@

bonus: $(OBJ_DIR) $(MLX) $(LIBFT) $(NAMEB)

clean:
	@echo "Removing object files of $(MLX)"
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "Removing object files of $(LIBFT)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Removing object files of $(NAME) and/or $(NAMEB)"
	@rm -f $(OBJ)
	@rm -f $(OBJ_B)
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi

fclean :clean
	@echo "Removing $(NAME) and/or $(NAMEB)"
	@rm -f $(NAME)
	@rm -f $(NAMEB)
	@echo "Removing $(LIBFT)"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
