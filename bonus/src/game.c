/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** game
*/

#include "sokoban.h"
#include "my.h"

void end_check(game_t *game, storage_t **storage, bonus_t *bonus)
{
    if (check_win(game, storage) == 1)
        exit_program(game, storage, 0, bonus);
    if (check_loose(game, storage) == 1)
        exit_program(game, storage, 1, bonus);
}

int start_game(game_t *game, storage_t **storage, \
bonus_t *bonus)
{
    int indic = 0;

    initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    while (1) {
        indic = check_tty_size(game, LINES, COLS);
        if (indic == 0) {
            clear();
            update_timer(bonus, game);
            update_move(bonus, game);
            end_check(game, storage, bonus);
            display_map(game);
            key_handle(game, bonus);
            check_storage_point(game, storage);
            usleep(9900);
        }
        refresh();
    }
    return (0);
}

int init_game(char **av)
{
    game_t *game = malloc(sizeof(game_t));
    storage_t **storage;
    char *file;
    bonus_t bonus;

    file = load_map(av[1]);
    if (file == NULL) {
        free(game);
        return (-1);
    }
    if (init_struct(game, file) == -1)
        return (-1);
    storage = init_storage(game);
    init_bonus(&bonus);
    start_game(game, storage, &bonus);
    destroy_game(game);
    destroy_storage(storage);
    return (0);
}