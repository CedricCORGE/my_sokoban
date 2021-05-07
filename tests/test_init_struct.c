/*
** EPITECH PROJECT, 2021
** test_init_struct.c
** File description:
** unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sokoban.h"

Test(init_map, malloc_failed)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 20);
    char file2[19] = "####\n\
# P#\n\
#  #\n\
####";
    int ret;

    for (int i = 0; i < 19; i++)
        file[i] = file2[i];
    ret = init_map(game, file, -10, 4);
    cr_assert_eq(ret, -1);
}

Test(init_original_map, malloc_failed)
{
    game_t *game = malloc(sizeof(game_t));
    char *file = malloc(sizeof(char) * 20);
    char file2[19] = "####\n\
# P#\n\
#  #\n\
####";
    int ret;

    for (int i = 0; i < 19; i++)
        file[i] = file2[i];
    ret = init_original_map(game, file, -10, 4);
    cr_assert_eq(ret, -1);
}