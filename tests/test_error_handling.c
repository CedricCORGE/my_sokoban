/*
** EPITECH PROJECT, 2021
** test_error_handling.c
** File description:
** unit test
*/

#include "sokoban.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(load_map, wrong_file, .init = redirect_all_stdout)
{
    char path[10] = "wrong_file";

    load_map(path);
    cr_assert_stderr_eq_str("Can't open the file\n");
}

Test(load_map, wrong_file2)
{
    char path[10] = "wrong_file";
    char *buffer = load_map(path);

    cr_assert_arr_eq(NULL, buffer, 0);
}

Test(load_file, failed_stat, .init = redirect_all_stdout)
{
    int fd = -1;
    struct stat s;

    stat("wrong_file", &s);
    load_file(s, fd);
    cr_assert_stderr_eq_str("malloc failed\n");
}

Test(load_file, failed_stat2)
{
    int fd = -1;
    struct stat s;
    char *buffer;

    stat("wrong_file", &s);
    buffer = load_file(s, fd);
    cr_assert_arr_eq(NULL, buffer, 0);
}

Test(load_file, wrong_fd, .init = redirect_all_stdout)
{
    int fd = -1;
    struct stat s;

    stat("map.txt", &s);
    load_file(s, fd);
    cr_assert_stderr_eq_str("read failed\n");
}

Test(load_file, wrong_fd2)
{
    int fd = -1;
    struct stat s;
    char *buffer;

    stat("map.txt", &s);
    buffer = load_file(s, fd);
    cr_assert_arr_eq(NULL, buffer, 0);
}