CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME=push_swap

push_swap:
	$(CC) $(CFLAGS) push_swap.c -o push_swap

.PHONY: all clean fclean re so