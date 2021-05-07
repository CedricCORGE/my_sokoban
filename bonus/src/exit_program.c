/*
** EPITECH PROJECT, 2021
** exit_program.c
** File description:
** exit program
*/

#include "sokoban.h"
#include "my.h"

void exit_program(game_t *game, storage_t **storage, \
int ret_value, bonus_t *bonus)
{
    destroy_game(game);
    destroy_storage(storage);
    endwin();
    destroy_bonus(bonus);
    if (ret_value == 0) {
        if (bonus->nb_minutes < 10 && bonus->nb_seconds < 10)
            my_printf("You finish the level in 0%d:0%d minutes and use %d \
moves\n", bonus->nb_minutes, bonus->nb_seconds, bonus->count_move);
        else if (bonus->nb_minutes < 10)
            my_printf("You finish the level in 0%d:%d minutes and use %d \
moves\n", bonus->nb_minutes, bonus->nb_seconds, bonus->count_move);
        else
            my_printf("You finish the level in %d:%d minutes and use %d \
moves\n", bonus->nb_minutes, bonus->nb_seconds, bonus->count_move);
    } else
        my_printf("You loose\n");
    exit(ret_value);
}