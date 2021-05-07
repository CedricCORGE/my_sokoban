/*
** EPITECH PROJECT, 2021
** load_map.c
** File description:
** load map
*/

#include "sokoban.h"
#include "my.h"

char *load_file(struct stat s, int fd)
{
    char *buffer;

    buffer = malloc(sizeof(char) * (s.st_size + 1));
    if (buffer == NULL) {
        my_puterror("malloc failed\n");
        return (NULL);
    }
    if (read(fd, buffer, s.st_size) == -1) {
        my_puterror("read failed\n");
        return (NULL);
    }
    buffer[s.st_size] = '\0';
    return (buffer);
}

char *load_map(char *path)
{
    int fd = open(path, O_RDONLY);
    char *buffer;
    struct stat s;

    if (fd == -1) {
        my_puterror("Can't open the file\n");
        return (NULL);
    }
    if (stat(path, &s) == -1) {
        my_puterror("stat failed\n");
        return (NULL);
    }
    buffer = load_file(s, fd);
    if (buffer == NULL)
        return (NULL);
    close(fd);
    if (check_map(buffer) == 1)
        return (NULL);
    return (buffer);
}