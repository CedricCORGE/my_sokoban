/*
** EPITECH PROJECT, 2021
** timer.c
** File description:
** timer
*/

#include "sokoban.h"
#include "my.h"

char *itc(int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 10);

    if (nb == 0) {
        str[i] = 48;
        str[i + 1] = '\0';
    } else {
        while (nb > 0) {
            str[i] = nb % 10 + 48;
            nb = nb / 10;
            i++;
        }
        str[i] = '\0';
        my_revstr(str);
    }
    return (str);
}

void draw_timer(bonus_t *bonus, int row)
{
    mvprintw(2, row + 5, "Time:");
    if (bonus->nb_minutes < 10)
        mvprintw(3, row + 9, "0");
    mvprintw(3, row + 10, itc(bonus->nb_minutes));
    mvprintw(3, row + 11, ":");
    if (bonus->nb_seconds < 10) {
        mvprintw(3, row + 12, "0");
        mvprintw(3, row + 13, itc(bonus->nb_seconds));
    } else
        mvprintw(3, row + 12, itc(bonus->nb_seconds));
}

void update_timer(bonus_t *bonus, game_t *game)
{
    sfTime time = sfClock_getElapsedTime(bonus->clock);
    float second = time.microseconds / 1000000.0;
    int row = 0;

    if (second > 1) {
        bonus->nb_seconds++;
        sfClock_restart(bonus->clock);
    }
    if (bonus->nb_seconds == 60) {
        bonus->nb_seconds = 0;
        bonus->nb_minutes++;
    }
    row = get_max_row(game);
    draw_timer(bonus, row);
}