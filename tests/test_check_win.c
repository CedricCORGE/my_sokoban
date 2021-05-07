/*
** EPITECH PROJECT, 2021
** test_check_win.c
** File description:
** unit game
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sokoban.h"

Test(check_win, one_storage)
{
    int ret = 0;
    game_t *game = malloc(sizeof(game_t));
    storage_t **storage;
    char *file = malloc(sizeof(char) * 35);
    char file2[34] = "######\n\
#  P #\n\
#  X #\n\
#   O#\n\
######";

    for (int i = 0; i < 34; i++)
        file[i] = file2[i];
    init_struct(game, file);
    storage = init_storage(game);
    down(game);
    left(game);
    down(game);
    right(game);
    ret = check_win(game, storage);
    cr_assert_eq(ret, 1);
    destroy_game(game);
    destroy_storage(storage);
}

Test(check_win, two_storage)
{
    int ret = 0;
    game_t *game = malloc(sizeof(game_t));
    storage_t **storage;
    char *file = malloc(sizeof(char) * 35);
    char file2[34] = "######\n\
#  P #\n\
#  XX#\n\
#  OO#\n\
######";

    for (int i = 0; i < 34; i++)
        file[i] = file2[i];
    init_struct(game, file);
    storage = init_storage(game);
    down(game);
    up(game);
    right(game);
    down(game);
    ret = check_win(game, storage);
    cr_assert_eq(ret, 1);
    destroy_game(game);
    destroy_storage(storage);
}

Test(check_win, not_win)
{
    int ret = 0;
    game_t *game = malloc(sizeof(game_t));
    storage_t **storage;
    char *file = malloc(sizeof(char) * 35);
    char file2[34] = "######\n\
#  P #\n\
#   X#\n\
#   O#\n\
######";

    for (int i = 0; i < 34; i++)
        file[i] = file2[i];
    init_struct(game, file);
    storage = init_storage(game);
    ret = check_win(game, storage);
    cr_assert_eq(ret, 0);
    destroy_game(game);
    destroy_storage(storage);
}