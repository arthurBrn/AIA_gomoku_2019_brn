/*
** EPITECH PROJECT, 2019
** gomoku.h
** File description:
** ..
*/

#ifndef _GOMOKU_H_
#define _GOMOKU_H_

#define BUFF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "board.h"
#include "move.h"

typedef struct {
    int size;
    int player;
    int start;
    int end;
    int begin;
    char **patterns;
    int *patterns_value;
    t_board *board;
} t_gomoku;

#define MY_EXIT_FAILURE 84
#define OK_MSG "OK - everything is good\n"
#define ERROR_MSG "ERROR message - unsupported size or other error\n"
#define GAME_STARTED "ERROR: The game is already start.\n"
#define ERROR_SIZE "ERROR: The parameters must be smaller than the size\n"
#define UNKNOWN "UNKNOWN: The commands doesn't exist.\n"
#define GAME_FINISH "none\n"
#define GAME_NOT_STARTED "ERROR: The game didn't start.\n"

int gomoku();
int run_start(char *str, t_gomoku *gomoku);
int run_end(char *str, t_gomoku *gomoku);
int run_begin(char *str, t_gomoku *gomoku);
int run_turn(char *str, t_gomoku *gomoku);
void run_cmd(int (**tab_cmd)(char *, t_gomoku *));
char **my_str_to_word_array(char *str, char *lim);
int isnum(char *str);
char *itoa(int nb, char *str, int size);
char *delete_zero(char *play);
t_board *init_board();
int storing_error(char *coordonate, t_gomoku *gomoku, char *delim);
int error_board(t_gomoku *gomoku, char *s1);
void set_node(t_board *board, char *coordonate, char *delim);
t_board *store_board(t_board *board, char *coordonate, char *delim);
int run_board(char *s1, t_gomoku *gomoku);
void print_list(t_board *board);
void print_node(t_board *board);
int list_length(t_board *board);
int nbr_coma(char *str);
int only_digit_str(char *str);
int check_players(char c);
int check_coordinate(char *str, t_gomoku *gomoku);
int check_string(char *str, t_gomoku *gomoku);
void print_the_board(t_gomoku *gom, t_board *board);
char *concat_coordonate(t_gomoku *gomoku, char *xy);
void swap(t_board *holder);
void sort_board(t_board *board);
bool check_open_1(int start_x, int start_y, int end_x, int end_y);
bool check_open_2(int start_x, int start_y, int end_x, int end_y);
void make_moves(t_move *move);
void sort_board_per_x(t_board *board, char *search_direction);
void sort_board_per_y(t_board *board, char *search_direction);
void free_board_list(t_board *board);
void init_struct(t_gomoku *gomoku);
int check_cmd(char *str, int (*tab_cmd[5])(), t_gomoku *gomoku);
int loop_read(t_gomoku *gomoku, int (*tab_cmd[5])(char *, t_gomoku *gomoku));
char *if_all_open_are_true(char *res, t_move *move);
char *if_only_second_open_are_true(char *res, t_move *move);
char *where_play(t_move *move);
void makes_moves(t_move *move);
void my_free_tab(char **tab);
int	my_delim(char s, char *lim);
int	count_word(char *str, char *lim);
int	wordlen(char *str, char *lim, int i);
char **my_str_to_word_array(char *str, char *lim);
int call_the_node(int x, int y, t_board *board);
int error_begin(t_gomoku *gomoku);
int store_begin_move(t_gomoku *gomoku, char *xy);
int run_begin(char *str, t_gomoku *gomoku);
int error_end(t_gomoku *gomoku);
int error_start(char *str, t_gomoku *gomoku);
int check_vertical(t_gomoku *gomoku);
void store_move(int *position, bool open1, bool open2);
int play_len(char *play);
t_move *init_move_struct();

#endif
