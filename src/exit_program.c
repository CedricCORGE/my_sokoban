/*
** EPITECH PROJECT, 2021
** exit_program.c
** File description:
** exit program
*/

#include "sokoban.h"
#include "my.h"

void exit_program(game_t *game, storage_t **storage, int ret_value)
{
    display_map(game);
    refresh();
    destroy_game(game);
    destroy_storage(storage);
    endwin();
    exit(ret_value);
}