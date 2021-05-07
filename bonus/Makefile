##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC				=	src/main.c					\
					src/load_map.c				\
					src/init_struct.c			\
					src/game.c					\
					src/check_map.c				\
					src/destroy.c				\
					src/movement.c				\
					src/direction.c				\
					src/check_usage.c			\
					src/get_map_size.c			\
					src/display_map.c			\
					src/key_handle.c			\
					src/restart_game.c			\
					src/check_loose.c			\
					src/init_storage.c			\
					src/exit_program.c			\
					src/check_win.c				\
					src/check_tty_size.c		\
					src/check_storage_point.c	\
					src/music.c					\
					src/timer.c					\
					src/init_bonus.c			\
					src/update_move.c			\
					src/get_storage_point.c

OBJ				=	$(SRC:.c=.o)

NAME			=	my_sokoban

CFLAGS			+=	-Wall -Werror -Wshadow -I include/

all:				$(NAME)

$(NAME):			$(OBJ)
					make re -C lib/my/
					cc $(OBJ) -lncurses -o $(NAME) -L./lib/ -lmy -lm -lcsfml-graphics -lcsfml-system -lcsfml-audio

unit_tests:
					make re -C lib/my/
					make re -C tests/

tests_run:
					./tests/unit_tests

clean:
					rm -f $(OBJ)

fclean:				clean
					rm -f $(NAME)
					make fclean -C lib/my/
					rm -f lib/libmy.a

re:					fclean all

.PHONY:
					all clean fclean re