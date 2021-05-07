/*
** EPITECH PROJECT, 2021
** direction.c
** File description:
** direction
*/

#include "sokoban.h"
#include "my.h"

int up(game_t *game)
{
    int x = game->x_player;
    int y = game->y_player;

    if (game->map[y - 1][x] == '#') {
        return (0);
    } else if (game->map[y - 1][x] == 'X' && game->map[y - 2][x] == '#')
        return (0);
    if (game->map[y - 1][x] == 'X' && game->map[y - 2][x] == 'X')
        return (0);
    if (game->map[y - 1][x] == 'X') {
        move_box(game, x, y - 2, 1);
        move_player(game, x, y - 1, 1);
    } else {
        move_player(game, x, y - 1, 1);
    }
    return (0);
}

int down(game_t *game)
{
    int x = game->x_player;
    int y = game->y_player;

    if (game->map[y + 1][x] == '#') {
        return (0);
    } else if (game->map[y + 1][x] == 'X' && game->map[y + 2][x] == '#')
        return (0);
    if (game->map[y + 1][x] == 'X' && game->map[y + 2][x] == 'X')
        return (0);
    if (game->map[y + 1][x] == 'X') {
        move_box(game, x, y + 2, 0);
        move_player(game, x, y + 1, 0);
    } else {
        move_player(game, x, y + 1, 0);
    }
    return (0);
}

int left(game_t *game)
{
    int x = game->x_player;
    int y = game->y_player;

    if (game->map[y][x - 1] == '#') {
        return (0);
    } else if (game->map[y][x - 1] == 'X' && game->map[y][x - 2] == '#')
        return (0);
    if (game->map[y][x - 1] == 'X' && game->map[y][x - 2] == 'X')
        return (0);
    if (game->map[y][x - 1] == 'X') {
        move_box(game, x - 2, y, 2);
        move_player(game, x - 1, y, 2);
    } else {
        move_player(game, x - 1, y, 2);
    }
    return (0);
}

int right(game_t *game)
{
    int x = game->x_player;
    int y = game->y_player;

    if (game->map[y][x + 1] == '#') {
        return (0);
    } else if (game->map[y][x + 1] == 'X' && game->map[y][x + 2] == '#')
        return (0);
    if (game->map[y][x + 1] == 'X' && game->map[y][x + 2] == 'X')
        return (0);
    if (game->map[y][x + 1] == 'X') {
        move_box(game, x + 2, y, 3);
        move_player(game, x + 1, y, 3);
    } else {
        move_player(game, x + 1, y, 3);
    }
    return (0);
}