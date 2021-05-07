##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC				=	src/check_loose.c			\
					src/check_map.c				\
					src/check_storage_point.c	\
					src/check_tty_size.c		\
					src/check_usage.c			\
					src/check_win.c				\
					src/destroy.c				\
					src/direction.c				\
					src/display_map.c			\
					src/exit_program.c			\
					src/game.c					\
					src/get_map_size.c			\
					src/get_storage_point.c		\
					src/init_storage.c			\
					src/init_struct.c			\
					src/key_handle.c			\
					src/load_map.c				\
					src/main.c					\
					src/movement.c				\
					src/restart_game.c			\

OBJ				=	$(SRC:.c=.o)

NAME			=	my_sokoban

CFLAGS			=	-Wall -Werror -Wshadow -Wextra -I include/

LDFLAGS			=	-L./lib -lmy -lncurses

CC				=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) -C lib/my/
			$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

bonus_compil:
			make re -C bonus/

unit_tests:
			make re -C lib/my/
			make re -C tests/

tests_run:
			$(MAKE) unit_tests
			./unit_tests
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			make fclean -C lib/my/
			make fclean -C tests/
			make fclean -C bonus/
			rm -f lib/libmy.a

re:			fclean all

.PHONY:
			all unit_tests tests_run clean bonus fclean re
