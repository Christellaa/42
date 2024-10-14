NAME := push_swap
NAMEB := checker
SRC_DIR := src
SRC := algorithms.c cleanup.c utils.c inits.c push_swap.c complex_sort.c \
complex_sort_utils.c min_moves.c operations.c
SRC_DIRB := src_bonus
SRCB := checker.c cleanup_bonus.c operations_bonus.c utils_bonus.c
OBJS_DIR := obj
OBJS := $(SRC:%.c=$(OBJS_DIR)/%.o)
OBJS_B := $(SRCB:%.c=$(OBJS_DIR)/%.o)
INCLUDES := inc/push_swap.h
INCLUDESB := inc_bonus/push_swap_bonus.h
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

all: $(OBJS_DIR) $(LIBFT) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS) $(INCLUDES)
	@echo "Building $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(NAMEB): $(LIBFT) $(OBJS_B) $(INCLUDESB)
	@echo "Building $(NAMEB)"
	@$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT) -o $(NAMEB)

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o : $(SRC_DIRB)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "Building $(LIBFT)"
	@$(MAKE) -C $(LIBFT_DIR)

bonus: $(OBJS_DIR) $(LIBFT) $(NAMEB)

clean:
	@echo "Removing object files"
	@rm -f $(OBJS) $(OBJSB)
	@if [ -d $(OBJS_DIR) ]; then rm -rf $(OBJS_DIR); fi
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Removing object files and $(NAME) or $(NAMEB)"
	@rm -f $(NAME) $(NAMEB)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
