/*
** EPITECH PROJECT, 2021
** display_map.c
** File description:
** display map
*/

#include "sokoban.h"
#include "my.h"

void display_map(game_t *game)
{
    for (int i = 0; game->map[i]; i++) {
        mvprintw(i, 0, game->map[i]);
    }
}