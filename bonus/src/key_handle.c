/*
** EPITECH PROJECT, 2021
** key_handle.c
** File description:
** key_handle
*/

#include "sokoban.h"
#include "my.h"

void count_move(bonus_t *bonus, int key)
{
    if (key != ERR && key != 32)
        bonus->count_move++;
}

void key_handle(game_t *game, bonus_t *bonus)
{
    int key = getch();

    count_move(bonus, key);
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