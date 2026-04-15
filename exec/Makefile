################################################################################
# Makefile for minishell
# - lists all .c files once in `SRC_FILES`
# - object files go to `obj/`
# - dependency files go to `dep/`
# - headers in `includes/`
################################################################################

CC := cc
CFLAGS := -Wall -Wextra -Werror -g -I includes 

NAME := minishell

SRC_DIR := src
OBJ_DIR := obj
DEP_DIR := dep
BUILTINS_DIR := src/built-ins
INCLUDES := includes
LDLIBS  = -lreadline -lhistory
HEADERS := $(INCLUDES)/exec.h

# List sources once by directory (basenames)
SRC_FILES := \
	child.c \
	dummy.c \
	env_list.c \
	executable.c \
	ft_atol.c \
	ft_split.c \
	ft_strjoin.c \
	helper.c \
	main.c \
	pipes.c \
	redirection.c \
	test.c \
	free.c \
	ft_itoa.c \
	heredoc.c \
	expansion.c
# 	expansion.c

BUILTINS_SRC_FILES := \
	built_in.c \
	built_in2.c \
	builtin_single.c \
	builtin_single2.c \
	export.c \
	cd.c \
	echo.c \
	single_builtin_execution.c \
	unset.c

# Object filenames: place in obj/ with same basenames
OBJS := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o) $(BUILTINS_SRC_FILES:.c=.o))

# Dependency files (one per object) in dep/
DEPS := $(addprefix $(DEP_DIR)/, $(SRC_FILES:.c=.d) $(BUILTINS_SRC_FILES:.c=.d))

.PHONY: all clean fclean re obj dep

all: $(NAME)

$(NAME): $(OBJS) | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)

$(OBJ_DIR):
	@if [ ! -d $(OBJ_DIR) ]; then echo "creating $(OBJ_DIR)"; mkdir -p $(OBJ_DIR); fi

$(DEP_DIR):
	@if [ ! -d $(DEP_DIR) ]; then echo "creating $(DEP_DIR)"; mkdir -p $(DEP_DIR); fi

# Pattern rules: compile from src/ or src/built-ins/ to obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MP -MF $(DEP_DIR)/$*.d

$(OBJ_DIR)/%.o: $(BUILTINS_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MP -MF $(DEP_DIR)/$*.d

clean:
	rm -f $(OBJS)
	rm -rf $(DEP_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Include dependency files if they exist (ignore missing files)
-include $(DEPS)

