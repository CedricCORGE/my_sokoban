/*
** EPITECH PROJECT, 2021
** init_game.c
** File description:
** init game struct
*/

#include "sokoban.h"
#include "my.h"

void copy_map_in_tab(char *file, game_t *game)
{
    int j = 0;
    int i = 0;
    int k = 0;
    int len_file = my_strlen(file);

    while (i < len_file) {
        j = 0;
        while (file[i] != '\n' && file[i] != '\0') {
            game->map[k][j] = file[i];
            game->original_map[k][j] = file[i];
            i++;
            j++;
        }
        game->map[k][j] = '\0';
        k++;
        i++;
    }
    game->map[k] = NULL;
    free(file);
}

void init_player(game_t *game)
{
    int i = 0;
    int j = 0;

    for (i = 0; game->map[i]; i++) {
        for (j = 0; game->map[i][j]; j++) {
            if (game->map[i][j] == 'P') {
                game->x_player = j;
                game->y_player = i;
                game->x_player_ori = j;
                game->y_player_ori = i;
            }
        }
    }
}

int init_map(game_t *game, char *file, int nb_lines, int nb_cols)
{
    int index = 0;

    game->map = malloc(sizeof(*game->map) * (nb_lines + 2));
    if (game->map == NULL) {
        return (-1);
    }
    for (int i = 0; i < nb_lines + 1; i++) {
        nb_cols = get_nb_cols(file, index);
        index += nb_cols;
        game->map[i] = malloc(sizeof(*game->map[i]) * (nb_cols + 1));
        if (game->map[i] == NULL) {
            return (-1);
        }
    }
    return (0);
}

int init_original_map(game_t *game, char *file, int nb_lines, int nb_cols)
{
    int index = 0;

    game->original_map = malloc(sizeof(char *) * (nb_lines + 2));
    if (game->original_map == NULL) {
        return (-1);
    }
    for (int i = 0; i < nb_lines + 1; i++) {
        nb_cols = get_nb_cols(file, index);
        index += nb_cols;
        game->original_map[i] = malloc(sizeof(char) * (nb_cols + 1));
        if (game->original_map[i] == NULL) {
            return (-1);
        }
    }
    return (0);
}

int init_struct(game_t *game, char *file)
{
    int nb_lines = get_nb_lines(file);
    int nb_cols = 0;

    if (init_map(game, file, nb_lines, nb_cols) == -1)
        return (-1);
    if (init_original_map(game, file, nb_lines, nb_cols) == -1)
        return (-1);
    copy_map_in_tab(file, game);
    init_player(game);
    return (0);
}