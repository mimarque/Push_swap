# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 18:26:42 by mimarque          #+#    #+#              #
#    Updated: 2022/05/16 14:13:31 by mimarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES:=$(wildcard *.c)

NAME=libft.a

LIBSO=libft.so

CC=gcc

CFLAGS=-Wall -Wextra -Werror

OBJ_DIR=obj/

HDR_NAME=libft.h

SRC_PATH=$(addprefix $(SRC_DIR), $(SRC_FILES))

SRC_NAMES=${SRC_FILES:.c=.o}

SRC_NAMES_O=$(addprefix $(OBJ_DIR), $(SRC_NAMES))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(SRC_NAMES)
	ar -rc $@ $(SRC_NAMES_O)
	ranlib $@

$(OBJ_DIR):
	mkdir $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)$@ 

clean:
	rm -rf $(OBJ_DIR)

sclean: clean
	rm -rf $(NAME) $(LIBSO)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC_FILES) $(BONUS_FILES)
	gcc -nostartfiles -shared -o libft.so $(SRC_FILES) $(BONUS_FILES)

.PHONY: all bonus clean sclean fclean re so
