/*
** EPITECH PROJECT, 2021
** test_restart_game.c
** File description:
** unit test
*/

#include "sokoban.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(restart_game, restart_game)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[34] = "######\n\
# X  #\n\
#  P #\n\
#   O#\n\
######";

    for (int i = 0; i < 34; i++)
        file[i] = file2[i];
    init_struct(game, file);
    down(game);
    left(game);
    restart_game(game);
    for (int i = 0; game->map[i]; i++) {
        cr_assert_arr_eq(game->map[i], game->original_map[i], 6);
    }
    destroy_game(game);
}