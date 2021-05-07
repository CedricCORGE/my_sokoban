/*
** EPITECH PROJECT, 2021
** test_check_loose.c
** File description:
** unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sokoban.h"

Test(check_loose, one_box)
{
    int ret = 0;
    game_t *game = malloc(sizeof(game_t));
    char *buffer = malloc(sizeof(char) * 34);
    char buffer2[34] = "######\n\
#   P#\n\
#   X#\n\
#   O#\n\
######";

    for (int i = 0; i < 34; i++)
        buffer[i] = buffer2[i];
    init_struct(game, buffer);
    down(game);
    ret = check_loose(game);
    cr_assert_eq(ret, 1);
    destroy_game(game);
}

Test(check_loose, one_box2)
{
    int ret = 0;
    game_t *game = malloc(sizeof(game_t));
    char *buffer = malloc(sizeof(char) * 34);
    char buffer2[34] = "######\n\
#P   #\n\
#X   #\n\
#   O#\n\
######";

    for (int i = 0; i < 34; i++)
        buffer[i] = buffer2[i];
    init_struct(game, buffer);
    down(game);
    ret = check_loose(game);
    cr_assert_eq(ret, 1);
    destroy_game(game);
}

Test(check_loose, one_box3)
{
    int ret = 0;
    game_t *game = malloc(sizeof(game_t));
    char *buffer = malloc(sizeof(char) * 34);
    char buffer2[34] = "######\n\
#    #\n\
#X   #\n\
#P  O#\n\
######";

    for (int i = 0; i < 34; i++)
        buffer[i] = buffer2[i];
    init_struct(game, buffer);
    up(game);
    ret = check_loose(game);
    cr_assert_eq(ret, 1);
    destroy_game(game);
}

Test(check_box_collision, two_box_corner)
{
    int ret = 0;
    game_t *game = malloc(sizeof(game_t));
    char *buffer = malloc(sizeof(char) * 34);
    char buffer2[34] = "######\n\
#   P#\n\
#  XX#\n\
#O  O#\n\
######";

    for (int i = 0; i < 34; i++)
        buffer[i] = buffer2[i];
    init_struct(game, buffer);
    down(game);
    up(game);
    left(game);
    left(game);
    down(game);
    right(game);
    ret = check_loose(game);
    cr_assert_eq(ret, 1);
    destroy_game(game);
}

Test(check_loose, two_box_corner2)
{
    int ret = 0;
    game_t *game = malloc(sizeof(game_t));
    char *buffer = malloc(sizeof(char) * 34);
    char buffer2[34] = "######\n\
# P  #\n\
#XX  #\n\
#O  O#\n\
######";

    for (int i = 0; i < 34; i++)
        buffer[i] = buffer2[i];
    init_struct(game, buffer);
    down(game);
    right(game);
    down(game);
    left(game);
    ret = check_loose(game);
    cr_assert_eq(ret, 1);
    destroy_game(game);
}

Test(check_loose, two_box_corner3)
{
    int ret = 0;
    game_t *game = malloc(sizeof(game_t));
    char *buffer = malloc(sizeof(char) * 34);
    char buffer2[34] = "######\n\
#X   #\n\
# X  #\n\
#OP O#\n\
######";

    for (int i = 0; i < 34; i++)
        buffer[i] = buffer2[i];
    init_struct(game, buffer);
    up(game);
    ret = check_loose(game);
    cr_assert_eq(ret, 1);
    destroy_game(game);
}

Test(check_loose, two_box_corner4)
{
    int ret = 0;
    game_t *game = malloc(sizeof(game_t));
    char *buffer = malloc(sizeof(char) * 34);
    char buffer2[34] = "######\n\
#   X#\n\
#  X #\n\
#O PO#\n\
######";

    for (int i = 0; i < 34; i++)
        buffer[i] = buffer2[i];
    init_struct(game, buffer);
    up(game);
    ret = check_loose(game);
    cr_assert_eq(ret, 1);
    destroy_game(game);
}

Test(check_loose, no_loose)
{
    int ret = 0;
    game_t *game = malloc(sizeof(game_t));
    char *buffer = malloc(sizeof(char) * 34);
    char buffer2[34] = "######\n\
#P   #\n\
#X   #\n\
#   O#\n\
######";

    for (int i = 0; i < 34; i++)
        buffer[i] = buffer2[i];
    init_struct(game, buffer);
    right(game);
    ret = check_loose(game);
    cr_assert_eq(ret, 0);
    destroy_game(game);
}