/*
** EPITECH PROJECT, 2021
** key_handle.c
** File description:
** key_handle
*/

#include "sokoban.h"
#include "my.h"

void key_handle(game_t *game)
{
    int key = getch();

    switch (key) {
        case KEY_UP:
            up(game);
            break;
        case KEY_DOWN:
            down(game);
            break;
        case KEY_LEFT:
            left(game);
            break;
        case KEY_RIGHT:
            right(game);
            break;
        case 32:
            restart_game(game);
            break;
    }
}