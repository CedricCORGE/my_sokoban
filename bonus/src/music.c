/*
** EPITECH PROJECT, 2021
** music.c
** File description:
** music
*/

#include "sokoban.h"

sfMusic *init_music(void)
{
    sfMusic *music = sfMusic_createFromFile("bonus/game_music.ogg");

    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 100);
    sfMusic_play(music);
    return (music);
}