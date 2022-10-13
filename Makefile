CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=push_swap

I_LIBFT=-Ilibft -Llibft -lft

LIBFT=libft/libft.a

push_swap: $(LIBFT)
	$(CC) $(CFLAGS) $(I_LIBFT) push_swap.c -o push_swap

$(LIBFT):
	@echo "compiling libft"
	make -C libft
	@echo "done libft"


.PHONY: all clean fclean re so