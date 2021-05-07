/*
** EPITECH PROJECT, 2021
** get_storage_point.c
** File description:
** get storage point
*/

#include "sokoban.h"
#include "my.h"

int get_storage_point(game_t *game)
{
    int cpt = 0;

    for (int i = 0; game->map[i]; i++) {
        for (int j = 0; game->map[i][j]; j++)
            if (game->map[i][j] == 'O')
                cpt++;
    }
    return (cpt);
}