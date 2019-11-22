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

typedef struct {
    int size;
    int player;
    int start;
    int end;
    char **tab;
} t_gomoku;

typedef struct node {
    int x;
    int y;
    int player;
    struct node *next;
} node_t;

#define ERROR 84
#define OK_MSG "OK - everything is good"
#define ERROR_MSG "ERROR message - unsupported size or other error\n"
#define GAME_STARTED "ERROR: The game is already start."
#define ERROR_SIZE "ERROR: The parameters must be smaller than the size"
#define UNKNOWN "UNKNOWN: The commands doesn't exist."
#define GAME_NOT_STARTED "ERROR: The game didn't start."

void init_struct(t_gomoku *gomoku);
int readstandard(t_gomoku *gomoku);
void run_cmd(int (**tab_cmd)(t_gomoku *, char *));
int run_board(t_gomoku *gomoku, char *str);
int run_start(t_gomoku *gomoku, char *str);
int run_end(t_gomoku *gomoku, char *str);
int run_turn(t_gomoku *gomoku, char *str);
char **my_str_to_word_array(char *str, char *lim);
int isnum(char *str);
char *board();
void init_struct(t_gomoku *gomoku);
int readstandard(t_gomoku *gomoku);
int my_intlen(int nb);
void invalid_string(void);
int nbr_coma(char *str);
int only_digit_str(char *str);
int check_players(char c);
int check_coordinate(char *str, t_gomoku *gom);
int check_string(char *str, t_gomoku *gom);
char **my_str_to_word_array(char *str, char *delimiter);
int list_length(node_t *node);
int matching_node(char *str, node_t *node);
node_t *add_node(char *str, node_t *node);
void store_board(char *str, t_gomoku *gomoku);
int run_begin(t_gomoku *gomoku, char *str);
int check_error(t_gomoku *gomoku, char *str);
void init_begin(t_gomoku *gom);
int check_cmd(char *str, int (*tab_cmd[5])(), t_gomoku *gomoku);
int get_coord_x(char *str);
int get_coord_y(char*str);
void check_turn_errors(t_gomoku *gomoku, char *str);
#endif
