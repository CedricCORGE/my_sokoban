##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile for unit_test
##

SRC		=	test_load_map.c			\
			test_error_handling.c	\
			test_check_map.c		\
			test_movement.c			\
			test_init_struct.c		\
			test_restart_game.c		\
			test_check_win.c		\
			test_check_loose.c		\
			../src/check_loose.c	\
			../src/init_storage.c	\
			../src/get_storage_point.c	\
			../src/check_win.c		\
			../src/destroy.c		\
			../src/init_struct.c	\
			../src/movement.c		\
			../src/get_map_size.c	\
			../src/direction.c		\
			../src/load_map.c		\
			../src/restart_game.c	\
			../src/check_map.c

OBJ     =	$(SRC:.c=.o)

NAME	=	unit_tests

CFLAGS  =	-Wall -Werror -Wshadow -Wextra -I ../include/ --coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
			cc $(OBJ) -o $(NAME) $(CFLAGS) -L../lib/ -lmy
			mv unit_tests ../

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f ../$(NAME)
			rm -f *.gcno
			rm -f *.gcda
			rm -f .c.gcov
			rm -f ../src/*.gcda
			rm -f ../src/*.gcno

re:			fclean all
