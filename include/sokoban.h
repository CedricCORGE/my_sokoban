/*
** EPITECH PROJECT, 2021
** sokkoban.h
** File description:
** sokoban header
*/

#ifndef SOKODAN_H_
#define SOKODAN_H_

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct game game_t;

typedef struct storage_point storage_t;

struct game
{
    char **map;
    char **original_map;
    int x_player;
    int y_player;
    int x_player_ori;
    int y_player_ori;
};

struct storage_point
{
    int pos_x;
    int pos_y;
};

char *load_map(char *path);

int init_struct(game_t *game, char *file);

void destroy_game(game_t *game);

int init_game(char **av);

int check_map(char *file);

int up(game_t *game);

int down(game_t *game);

int left(game_t *game);

int right(game_t *game);

void move_box(game_t *game, int new_x, int new_y, int indic);

void move_player(game_t *game, int new_x, int new_y, int indic);

int check_usage(int ac, char **av);

void key_handle(game_t *game);

int get_nb_lines(char *file);

int get_nb_cols(char *file, int index);

void display_map(game_t *game);

void restart_game(game_t *game);

storage_t **init_storage(game_t *game);

void destroy_storage(storage_t **storage);

int get_storage_point(game_t *game);

int check_loose(game_t *game);

int check_win(game_t *game, storage_t **storage);

void exit_program(game_t *game, storage_t **storage, int ret_value);

int check_tty_size(game_t *game, int LINES, int COLS);

void check_storage_point(game_t *game, storage_t **storage);

char *load_file(struct stat s, int fd);

int check_storage(char *file);

int init_map(game_t *game, char *file, int nb_lines, int nb_cols);

int init_original_map(game_t *game, char *file, int nb_lines, int nb_cols);

int make_stat(char *path, struct stat *s);

#endif /* !SOKODAN_H_ */