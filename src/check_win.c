/*
** EPITECH PROJECT, 2021
** check_win.c
** File description:
** check win
*/

#include "sokoban.h"
#include "my.h"

int check_win(game_t *game, storage_t **storage)
{
    for (int i = 0; storage[i]; i++) {
        if (game->map[storage[i]->pos_y][storage[i]->pos_x] != 'X') {
            return (0);
        }
    }
    return (1);
}