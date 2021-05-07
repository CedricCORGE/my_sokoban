/*
** EPITECH PROJECT, 2021
** check_loose.c
** File description:
** check_loose
*/

#include "sokoban.h"
#include "my.h"

int check_double_box(game_t *game, int i, int j)
{
    if ((game->map[i][j + 1] == '#' && game->map[i - 1][j] == 'X') || \
(game->map[i][j + 1] == 'X' && game->map[i - 1][j] == '#'))
        return (1);
    if ((game->map[i - 1][j] == '#' && game->map[i][j - 1] == 'X') || \
(game->map[i - 1][j] == 'X' && game->map[i][j - 1] == '#'))
        return (1);
    if ((game->map[i][j - 1] == '#' && game->map[i + 1][j] == 'X') || \
(game->map[i][j - 1] == 'X' && game->map[i + 1][j] == '#'))
        return (1);
    if ((game->map[i][j + 1] == '#' && game->map[i + 1][j] == 'X') || \
(game->map[i][j + 1] == 'X' && game->map[i + 1][j] == '#'))
        return (1);
    return (0);
}

int check_localitation(game_t *game, int i, int j)
{
    if (game->map[i][j + 1] == '#' && game->map[i - 1][j] == '#')
        return (1);
    if (game->map[i - 1][j] == '#' && game->map[i][j - 1] == '#')
        return (1);
    if (game->map[i][j - 1] == '#' && game->map[i + 1][j] == '#')
        return (1);
    if (game->map[i][j + 1] == '#' && game->map[i + 1][j] == '#')
        return (1);
    if (check_double_box(game, i, j) == 1)
        return (1);
    return (0);
}

int is_in_storage(game_t *game, storage_t **storage, int i, int j)
{
    for (int k = 0; storage[k]; k++) {
        if (i == storage[k]->pos_y && j == storage[k]->pos_x)
            return (1);
    }
    return (0);
}

int check_movement(game_t *game, storage_t **storage, int i, int j)
{
    if (game->map[i][j] == 'X')
        if (check_localitation(game, i, j) == 0 && \
is_in_storage(game, storage, i, j) == 0)
            return (0);
    return (1);
}

int check_loose(game_t *game, storage_t **storage)
{
    for (int i = 0; game->map[i]; i++) {
        for (int j = 0; game->map[i][j]; j++) {
            if (check_movement(game, storage, i, j) == 0)
                return (0);
        }
    }
    return (1);
}