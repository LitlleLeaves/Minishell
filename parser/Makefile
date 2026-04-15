NAME    := MINISHELL

# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g #-fsanitize=address,undefined
LDFLAGS = -lreadline

#Source files
SRC :=	ft_helpers.c \
		loop_shell.c \
		token_funcs.c\
		token_garbage.c\
		expansion.c\

#obj
OBJ := $(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(HEADERS)-o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf build

re: fclean all

.PHONY: all clean fclean re
