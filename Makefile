# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchicote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 19:09:21 by cchicote          #+#    #+#              #
#    Updated: 2019/03/06 20:50:03 by cchicote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a
TEST_NAME = test
SRC_PATH = ./src/
TEST_PATH = ./tests/
OBJ_PATH = ./obj/
OBJ_TEST_PATH = ./obj_test/
ARCH = macho64

SRCS = ft_bzero.s \
	ft_strcat.s \
	ft_strlen.s 
TEST_SRCS = test_bzero.c \
		test_strcat.c \
		test_strlen.c		
OBJ = $(SRCS:%.s=$(OBJ_PATH)%.o)
TEST_OBJ = $(TEST_SRCS:%.c=$(OBJ_TEST_PATH)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.s
	mkdir -p $(OBJ_PATH)
	nasm -f $(ARCH) $< -o $@

clean:
	@ echo "Cleaning .o files"
	@ /bin/rm -Rf $(OBJ_PATH)

fclean: clean
	@ echo "Cleaning $(NAME)"
	@ /bin/rm -f $(NAME)

$(OBJ_TEST_PATH)%.o: $(TEST_PATH)%.c
	@ mkdir -p $(OBJ_TEST_PATH)
	@ gcc -Wall -Werror -Wextra -o $@ -c $<

compil_test: $(NAME) $(TEST_OBJ)
	@ gcc -Wall -Werror -Wextra main.c -o $(TEST_NAME) $(TEST_OBJ) -L. -lfts

test: compil_test
	@ ./$(TEST_NAME)

clean_test:
	@ /bin/rm -Rf $(OBJ_TEST_PATH)

fclean_test: clean_test
	@ /bin/rm -f $(TEST_NAME)

re_test: fclean_test test

re: fclean all

.PHONY: clean, fclean, re, all
