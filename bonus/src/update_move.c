/*
** EPITECH PROJECT, 2021
** update_move.c
** File description:
** update move
*/

#include "sokoban.h"

void update_move(bonus_t *bonus, game_t *game)
{
    int row = get_max_row(game);

    mvprintw(5, row + 5, "Move:");
    mvprintw(6, row + 9, itc(bonus->count_move));
}