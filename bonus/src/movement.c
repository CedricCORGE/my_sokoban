/*
** EPITECH PROJECT, 2021
** movement.c
** File description:
** movement of object
*/

#include "sokoban.h"
#include "my.h"

void move_player(game_t *game, int new_x, int new_y, int indic)
{
    game->map[new_y][new_x] = 'P';
    switch (indic) {
        case 0:
            game->map[new_y - 1][new_x] = ' ';
            break;
        case 1:
            game->map[new_y + 1][new_x] = ' ';
            break;
        case 2:
            game->map[new_y][new_x + 1] = ' ';
            break;
        case 3:
            game->map[new_y][new_x - 1] = ' ';
            break;
    }
    game->x_player = new_x;
    game->y_player = new_y;
}

void move_box(game_t *game, int new_x, int new_y, int indic)
{
    game->map[new_y][new_x] = 'X';
    switch (indic) {
        case 0:
            game->map[new_y - 1][new_x] = ' ';
            break;
        case 1:
            game->map[new_y + 1][new_x] = ' ';
            break;
        case 2:
            game->map[new_y][new_x + 1] = ' ';
            break;
        case 3:
            game->map[new_y][new_x - 1] = ' ';
            break;
    }
}