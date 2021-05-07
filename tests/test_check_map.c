/*
** EPITECH PROJECT, 2021
** test_check_map.c
** File description:
** unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sokoban.h"

void redirect_all_stdout(void);

Test(check_map, invalid_map, .init = redirect_all_stdout)
{
    char file2[78] = "############\n\
# O        #\n\
#          #\n\
#   X   ####\n\
#          #\n\
############";
    char *file = malloc(sizeof(char) * 79);

    for (int i = 0; i < 79; i++)
        file[i] = file2[i];
    check_map(file);
    cr_assert_stderr_eq_str("The game need one player\n");
}

Test(check_map, invalid_map2, .init = redirect_all_stdout)
{
    char file2[78] = "############\n\
# O        #\n\
#   fg     #\n\
#   X   ####\n\
#          #\n\
############";
    char *file = malloc(sizeof(char) * 79);

    for (int i = 0; i < 79; i++)
        file[i] = file2[i];
    check_map(file);
    cr_assert_stderr_eq_str("file isn't valide, check -h\n");
}

Test(check_map, invalid_map3, .init = redirect_all_stdout)
{
    char file2[78] = "############\n\
#  X       #\n\
#          #\n\
#       ####\n\
#      P   #\n\
############";
    char *file = malloc(sizeof(char) * 79);

    for (int i = 0; i < 79; i++)
        file[i] = file2[i];
    check_map(file);
    cr_assert_stderr_eq_str("The map need the same number of boxes and storage locations\n");
}