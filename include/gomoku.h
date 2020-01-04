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
#include "board.h"

typedef struct {
    int size;
    int player;
    int start;
    int end;
    int begin;
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
t_board *store_move(t_board *board, char *coordonate, char *delim);
int run_board(char *s1, t_gomoku *gomoku);
void print_list(t_board *board);
void print_node(t_board *board);
int list_length(t_board *board);
int nbr_coma(char *str); // will be to change 
int only_digit_str(char *str);
int check_players(char c);
int check_coordinate(char *str, t_gomoku *gomoku);
int check_string(char *str, t_gomoku *gomoku);
char *concat_player(char *str);
void print_the_board(t_gomoku *gom, t_board *board);
char *concat_coordonate(t_gomoku *gomoku, char *xy);

#endif
