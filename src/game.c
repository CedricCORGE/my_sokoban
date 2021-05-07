/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** game
*/

#include "sokoban.h"
#include "my.h"

int start_game(game_t *game, storage_t **storage)
{
    int indic = 0;

    initscr();
    keypad(stdscr, TRUE);
    while (1) {
        indic = check_tty_size(game, LINES, COLS);
        if (indic == 0) {
            clear();
            display_map(game);
            key_handle(game);
            check_storage_point(game, storage);
            if (check_win(game, storage) == 1)
                exit_program(game, storage, 0);
            if (check_loose(game) == 1)
                exit_program(game, storage, 1);
        }
    }
    return (0);
}

int init_game(char **av)
{
    game_t *game = malloc(sizeof(game_t));
    storage_t **storage;
    char *file;

    file = load_map(av[1]);
    if (file == NULL) {
        free(game);
        return (-1);
    }
    if (init_struct(game, file) == -1)
        return (-1);
    storage = init_storage(game);
    start_game(game, storage);
    destroy_game(game);
    destroy_storage(storage);
    return (0);
}