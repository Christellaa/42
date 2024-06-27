# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cde-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 10:01:11 by cde-sous          #+#    #+#              #
#    Updated: 2024/06/19 14:36:24 by cde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CFLAGS := -Wall -Wextra -Werror

SRCFILES := $(wildcard *.c)

OBJS := $(SRCFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:%.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
