/*
** EPITECH PROJECT, 2021
** destroy.c
** File description:
** destroy struct
*/

#include "sokoban.h"
#include "my.h"

void destroy_game(game_t *game)
{
    for (int i = 0; game->map[i]; i++) {
        free(game->map[i]);
    }
    free(game->map);
    for (int i = 0; game->original_map[i]; i++) {
        free(game->original_map[i]);
    }
    free(game->original_map);
    free(game);
}