SRC := srcs
SRCFILES := ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
OBJS := $(addprefix $(SRC)/, $(SRCFILES:%.c=%.o))
HD := includes
CC := cc
CFLAGS := -Wall -Werror -Wextra
TARGET := libft.a

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS)

$(OBJS): $(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -I $(HD) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(TARGET)
re: fclean all
.PHONY: all clean fclean re
