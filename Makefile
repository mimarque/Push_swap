CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=push_swap
OBJ_DIR=obj/
I_LIBFT=-Ilibft -Llibft -lft
LIBFT=libft/libft.a
SRC_FILES:=$(wildcard *.c)
SRC_NAMES=$(patsubst %.c,%.o,$(SRC_FILES))
SRC_NAMES_O=$(addprefix $(OBJ_DIR), $(SRC_NAMES))

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(NAME): $(SRC_NAMES_O) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(SRC_NAMES_O)  $(I_LIBFT) -o $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) $(I_LIBFT) -c $< -o $@ 

$(LIBFT):
	@echo "compiling libft"
	make -C libft
	@echo "done libft"

clean:
	rm -rf obj/
	make -C libft $@

fclean: clean
	rm -f push_swap
	make -C libft $@

re: fclean all

.PHONY: all clean fclean re