# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 10:01:11 by cde-sous          #+#    #+#              #
#    Updated: 2024/08/04 16:47:14 by cde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRCDIRS := check conversion fd_operations ft_printf get_next_line list memory \
string

SRCFILES := $(shell find $(DIRS) -name '*.c')

HEADERS := libfbt.h ft_printf/ft_printf.h get_next_line/get_next_line.h \
get_next_line/get_next_line_bonus.h

OBJS := $(SRCFILES:.c=.o)

CC := gcc

CFLAGS := -Wall -Wextra -Werror $(addprefix -I, $(dir $(HEADERS)))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building library"
	@ar rcs $@ $^

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing object files and $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
