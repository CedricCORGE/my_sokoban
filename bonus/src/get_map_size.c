/*
** EPITECH PROJECT, 2021
** get_map_size.c
** File description:
** get map size
*/

#include "sokoban.h"
#include "my.h"

int get_nb_lines(char *file)
{
    int cpt = 0;

    for (int i = 0; file[i]; i++) {
        if (file[i] == '\n')
            cpt++;
    }
    return (cpt);
}

int get_nb_cols(char *file, int index)
{
    int cpt = 0;

    while (file[index] != '\n' && file[index] != '\0') {
        index++;
        cpt++;
    }
    return (cpt + 1);
}

int get_max_row(game_t *game)
{
    int save = 0;

    for (int i = 0; game->map[i]; i++) {
        if (save < my_strlen(game->map[i]))
            save = my_strlen(game->map[i]);
    }
    return (save);
}