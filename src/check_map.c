/*
** EPITECH PROJECT, 2021
** check_map.c
** File description:
** check map
*/

#include "sokoban.h"
#include "my.h"

int check_player(char *file)
{
    for (int i = 0; file[i]; i++) {
        if (file[i] == 'P')
            return (0);
    }
    my_puterror("The game need one player\n");
    return (-1);
}

int check_storage(char *file)
{
    int cpt_box = 0;
    int cpt_endpoint = 0;

    for (int i = 0; file[i]; i++) {
        if (file[i] == 'X')
            cpt_box++;
        if (file[i] == 'O')
            cpt_endpoint++;
    }
    if (cpt_endpoint != cpt_box) {
        my_puterror("The map need the same number of \
boxes and storage locations\n");
        return (-1);
    } else
        return (0);
}

int check_map(char *file)
{
    for (int i = 0; file[i]; i++) {
        if (file[i] != '#' && file[i] != ' ' && file[i] != 'P' \
&& file[i] != 'O' && file[i] != '\n' && file[i] != 'X') {
            my_puterror("file isn't valide, check -h\n");
            free(file);
            return (1);
        }
    }
    if (check_player(file) == -1) {
        free(file);
        return (1);
    }
    if (check_storage(file) == -1) {
        free(file);
        return (1);
    }
    return (0);
}