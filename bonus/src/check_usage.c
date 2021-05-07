/*
** EPITECH PROJECT, 2021
** check_usage.c
** File description:
** check usage
*/

#include "sokoban.h"
#include "my.h"

void print_usage(void)
{
    my_printf("USAGE\n");
    my_printf("     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("     map file representing the warehouse map");
    my_printf(", containing '#' for walls, \n");
    my_printf("'P' for the player, ");
    my_printf("'X' for boxes and 'O' for storage locations\n");
}

int check_usage(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        print_usage();
        return (1);
    }
    return (0);
}