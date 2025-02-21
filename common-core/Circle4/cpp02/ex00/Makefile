NAME := fixed
INCFILES := Fixed.hpp
SRCFILES := main.cpp Fixed.cpp
OBJS := $(SRCFILES:.cpp=.o)
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCFILES)
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
