NAME := push_swap
NAMEB := push_swap_bonus
SRC_DIR := src
SRC := push_swap.c push.c swap.c rotate.c reverse_rotate.c cleanup.c
SRC_DIRB := src_bonus
SRCB := push_swap_bonus.c push_bonus.c swap_bonus.c rotate_bonus.c reverse_totate.c
OBJS_DIR := obj
OBJS := $(SRC:%.c=$(OBJS_DIR)/%.o)
OBJS_B := $(SRCB:%.c=$(OBJS_DIR)/%.o)
INCLUDES := inc/push_swap.h
INCLUDESB := inc/push_swap_bonus.h
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

$(NAMEB): $(LIBFT) $(OBJSB) $(INCLUDESB)
	@echo "Building $(NAMEB)"
	@$(CC) $(CFLAGS) $(OBJSB) $(LIBFT) -o $(NAMEB)

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o : $(SRC_DIR_B)/%.c
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