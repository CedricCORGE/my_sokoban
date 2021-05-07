/*
** EPITECH PROJECT, 2021
** init_storage.c
** File description:
** init storage
*/

#include "sokoban.h"
#include "my.h"

int load_position(storage_t **storage, game_t *game, int storage_number)
{
    int cpt = 0;

    for (int i = 0; game->map[i]; i++) {
        for (int j = 0; game->map[i][j]; j++) {
            if (game->map[i][j] == 'O' && cpt == storage_number) {
                storage[storage_number]->pos_x = j;
                storage[storage_number]->pos_y = i;
                return (0);
            } else if (game->map[i][j] == 'O' && cpt < storage_number)
                cpt++;
        }
    }
    return (0);
}

storage_t **init_storage(game_t *game)
{
    int nb_storage_point = get_storage_point(game);
    storage_t **storage = malloc(sizeof(storage_t *) * (nb_storage_point + 1));
    int i = 0;

    if (storage == NULL)
        return (NULL);
    for (i = 0; i < nb_storage_point; i++) {
        storage[i] = malloc(sizeof(storage_t));
        load_position(storage, game, i);
        if (storage[i] == NULL)
            return (NULL);
    }
    storage[i] = NULL;
    return (storage);
}

void destroy_storage(storage_t **storage)
{
    for (int i = 0; storage[i]; i++) {
        free(storage[i]);
    }
    free(storage);
}