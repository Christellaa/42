# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 10:55:36 by cde-sous          #+#    #+#              #
#    Updated: 2024/06/27 10:56:15 by cde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						= gnl

SRCS						= main.c get_next_line.c get_next_line_utils.c
SRCS_BONUS			= main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
INCLUDES				= get_next_line.h
INCLUDES_BONUS	= get_next_line_bonus.h
OBJS						= $(SRCS:.c=.o)
OBJS_BONUS			= $(SRCS_BONUS:.c=.o)

CC							= cc
CFLAGS					= -Wall -Wextra -Werror
EXTRAFLAGS			= -g3 -D BUFFER_SIZE=10

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	@echo "Compiling"
	@$(CC) $(CFLAGS) $(EXTRAFLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJS_BONUS) $(INCLUDES_BONUS)
	@echo "Compiling bonus"
	@$(CC) $(CFLAGS) $(EXTRAFLAGS) $(OBJS_BONUS) -o $(NAME)

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(EXTRAFLAGS) -c $< -o $@

clean:
	@echo "Removing objects files"
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
