/*
** EPITECH PROJECT, 2021
** test_movement.c
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sokoban.h"

Test(left, left)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# X  #\n\
#  P #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    left(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# X  #", 6);
    cr_assert_arr_eq(game->map[2], "# P  #", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(left, left_box)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# XP #\n\
#    #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    left(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "#XP  #", 6);
    cr_assert_arr_eq(game->map[2], "#    #", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(left, left_wall)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# X  #\n\
#P   #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    left(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# X  #", 6);
    cr_assert_arr_eq(game->map[2], "#P   #", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(left, left_box_wall)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
#XP  #\n\
#    #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    left(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "#XP  #", 6);
    cr_assert_arr_eq(game->map[2], "#    #", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(left, left_box_box)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
#XXP #\n\
#    #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    left(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "#XXP #", 6);
    cr_assert_arr_eq(game->map[2], "#    #", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(right, right)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# X  #\n\
#  P #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    right(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# X  #", 6);
    cr_assert_arr_eq(game->map[2], "#   P#", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(right, right_box)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
#PX  #\n\
#    #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    right(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# PX #", 6);
    cr_assert_arr_eq(game->map[2], "#    #", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(right, right_wall)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# X  #\n\
#   P#\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    right(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# X  #", 6);
    cr_assert_arr_eq(game->map[2], "#   P#", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(right, right_box_wall)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
#  PX#\n\
#    #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    right(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "#  PX#", 6);
    cr_assert_arr_eq(game->map[2], "#    #", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(right, right_box_box)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# PXX#\n\
#    #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    right(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# PXX#", 6);
    cr_assert_arr_eq(game->map[2], "#    #", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(up, up)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# X  #\n\
#  P #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    up(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# XP #", 6);
    cr_assert_arr_eq(game->map[2], "#    #", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(up, up_box)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
#    #\n\
# X  #\n\
# P O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    up(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# X  #", 6);
    cr_assert_arr_eq(game->map[2], "# P  #", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(up, up_wall)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# XP #\n\
#    #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    up(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# XP #", 6);
    cr_assert_arr_eq(game->map[2], "#    #", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(up, up_wall_box)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# X  #\n\
# P  #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    up(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# X  #", 6);
    cr_assert_arr_eq(game->map[2], "# P  #", 6);
    cr_assert_arr_eq(game->map[3], "#   O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(up, up_box_box)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# X  #\n\
# X  #\n\
# P O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    up(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# X  #", 6);
    cr_assert_arr_eq(game->map[2], "# X  #", 6);
    cr_assert_arr_eq(game->map[3], "# P O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(down, down)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# X  #\n\
#  P #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    down(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# X  #", 6);
    cr_assert_arr_eq(game->map[2], "#    #", 6);
    cr_assert_arr_eq(game->map[3], "#  PO#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(down, down_box)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# P  #\n\
# X  #\n\
#   O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    down(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "#    #", 6);
    cr_assert_arr_eq(game->map[2], "# P  #", 6);
    cr_assert_arr_eq(game->map[3], "# X O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(down, down_wall)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# X  #\n\
#    #\n\
#  PO#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    down(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# X  #", 6);
    cr_assert_arr_eq(game->map[2], "#    #", 6);
    cr_assert_arr_eq(game->map[3], "#  PO#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(down, down_box_wall)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
#    #\n\
# P  #\n\
# X O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    down(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "#    #", 6);
    cr_assert_arr_eq(game->map[2], "# P  #", 6);
    cr_assert_arr_eq(game->map[3], "# X O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}

Test(down, down_box_box)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 35);
    char file2[35] = "######\n\
# P  #\n\
# X O#\n\
# X O#\n\
######";

    for (int i = 0; i < 35; i++)
        file[i] = file2[i];
    init_struct(game, file);
    down(game);
    cr_assert_arr_eq(game->map[0], "######", 6);
    cr_assert_arr_eq(game->map[1], "# P  #", 6);
    cr_assert_arr_eq(game->map[2], "# X O#", 6);
    cr_assert_arr_eq(game->map[3], "# X O#", 6);
    cr_assert_arr_eq(game->map[4], "######", 6);
    destroy_game(game);
}