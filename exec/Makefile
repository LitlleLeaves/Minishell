NAME    := MINISHELLL

# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g -fsanitize=address

#Source files
SRC := 
# libft
LIBFTDIR := ../Libft
LIBFT := $(LIBFTDIR)/libft.a

#obj
OBJ := $(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean
	rm -rf build

re: fclean all

.PHONY: all clean fclean re
