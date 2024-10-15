NAME := philo_bonus
SRCFILES := philo_bonus.c
OBJS := $(SRCFILES:.c=.o)
INCLUDES := philo_bonus.h
CC := gcc
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	@echo "Building $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

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
