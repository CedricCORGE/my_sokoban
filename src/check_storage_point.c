/*
** EPITECH PROJECT, 2021
** check_storage_point.c
** File description:
** check storage point
*/

#include "sokoban.h"
#include "my.h"

void check_storage_point(game_t *game, storage_t **storage)
{
    for (int i = 0; storage[i]; i++) {
        if (game->map[storage[i]->pos_y][storage[i]->pos_x] == ' ') {
            game->map[storage[i]->pos_y][storage[i]->pos_x] = 'O';
        }
    }
}