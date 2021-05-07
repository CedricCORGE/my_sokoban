/*
** EPITECH PROJECT, 2021
** test_load_map.c
** File description:
** unit test
*/

#include "sokoban.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(load_map, short_map)
{
    char path[13] = "short_map.txt";
    char *buffer = load_map(path);

    cr_assert_arr_eq(buffer, "######\n\
#    #\n\
# PX #\n\
#   O#\n\
######", 34);
    free(buffer);
}

Test(load_map, medium_map)
{
    char path[7] = "map.txt";
    char *buffer = load_map(path);

    cr_assert_arr_eq(buffer, "############\n\
# O        #\n\
#          #\n\
#       X  #\n\
#          #\n\
#     X    #\n\
#          #\n\
#  P       #\n\
#    O     #\n\
#          #\n\
############", 142);
    free(buffer);
}

Test(load_map, big_map)
{
    char path[11] = "big_map.txt";
    char *buffer = load_map(path);

    cr_assert_arr_eq(buffer, "###########################################\n\
#                    O                    #\n\
#                                         #\n\
#                               X         #\n\
#                                         #\n\
#                                         #\n\
#            X                     O      #\n\
#                                         #\n\
#                                         #\n\
#                         X               #\n\
#                                         #\n\
#        P                                #\n\
#                                         #\n\
#                                         #\n\
#                                         #\n\
#                                         #\n\
#                                         #\n\
#              X              O           #\n\
#                                         #\n\
#                                         #\n\
#   O                                     #\n\
#                                         #\n\
#                      X       O          #\n\
#                                         #\n\
###########################################", 1099);
    free(buffer);
}

Test(make_stat, fail_stat)
{
    char path[10] = "wrong_path";
    struct stat s;
    int ret = 0;

    ret = make_stat(path, &s);
    cr_assert_eq(ret, -1);
}

Test(make_stat, good_stat)
{
    char path[7] = "map.txt";
    struct stat s;
    int ret = 0;

    ret = make_stat(path, &s);
    cr_assert_eq(ret, 0);
}

Test(load_map, invalid_map)
{
    char path[13] = "wrong_map.txt";
    char *buffer;

    buffer = load_map(path);
    cr_assert_arr_eq(NULL, buffer, 0);
}

Test(load_map, invalid_map2, .init = redirect_all_stdout)
{
    char path[13] = "wrong_map.txt";

    load_map(path);
    cr_assert_stderr_eq_str("The map need the same number of \
boxes and storage locations\n");
}