/*
** EPITECH PROJECT, 2021
** init_bonus
** File description:
** init bonus struct
*/

#include "sokoban.h"

void init_bonus(bonus_t *bonus)
{
    bonus->clock = sfClock_create();
    bonus->music = sfMusic_createFromFile("bonus/game_music.ogg");
    sfMusic_setLoop(bonus->music, sfTrue);
    sfMusic_setVolume(bonus->music, 100);
    sfMusic_play(bonus->music);
    bonus->nb_seconds = 0;
    bonus->nb_minutes = 0;
    bonus->count_move = 0;
}

void destroy_bonus(bonus_t *bonus)
{
    sfClock_destroy(bonus->clock);
    sfMusic_destroy(bonus->music);
}