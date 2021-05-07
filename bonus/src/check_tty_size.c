/*
** EPITECH PROJECT, 2021
** check_tty_size.c
** File description:
** check tty size
*/

#include "sokoban.h"
#include "my.h"

int get_nbcols_max(game_t *game)
{
    int save = 0;
    int j = 0;

    for (int i = 0; game->map[i]; i++) {
        for (j = 0; game->map[i][j]; j++);
        if (j > save) {
            save = j;
        }
        j = 0;
    }
    return (save);
}

int get_nblines(game_t *game)
{
    int i = 0;

    for (i = 0; game->map[i]; i++);
    return (i);
}

int check_tty_size(game_t *game, int LINES, int COLS)
{
    int nb_cols = get_nbcols_max(game);
    int nb_lines = get_nblines(game);
    char str[32] = "You have to enlarge the terminal";

    clear();
    if (LINES < nb_lines || COLS < nb_cols) {
        mvprintw(LINES / 2, ((COLS / 2) - (my_strlen(str) / 2)), str);
        keypad(stdscr, FALSE);
        usleep(1000);
        return (1);
    }
    keypad(stdscr, TRUE);
    return (0);
}