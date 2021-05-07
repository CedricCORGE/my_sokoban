/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "sokoban.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (check_usage(ac, av) == 1)
        return (0);
    if (init_game(av) == -1)
        return (84);
    return (0);
}