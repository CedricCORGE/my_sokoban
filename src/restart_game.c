/*
** EPITECH PROJECT, 2021
** restart_game.c
** File description:
** restart game
*/

#include "sokoban.h"
#include "my.h"

void restart_map(game_t *game)
{
    for (int i = 0; game->original_map[i]; i++) {
        for (int j = 0; game->original_map[i][j]; j++) {
            game->map[i][j] = game->original_map[i][j];
        }
    }
}

void restart_game(game_t *game)
{
    restart_map(game);
    game->x_player = game->x_player_ori;
    game->y_player = game->y_player_ori;
}