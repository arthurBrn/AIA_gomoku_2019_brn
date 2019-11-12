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
    int start;
    int end;
    char **tab;
} t_gomoku;

typedef struct node
{
    int x;
    int y;
    int player;
    struct node *next;
} node_t;

#define EXIT_USAGE 84
#define ERROR_MSG "error"
#define SYNTAX_ERROR_MSG "Syntax error."
#define EXIT_TURN 84

#define UNKNOW "UNKNOW"
#define ERROR "ERROR"

void    init_struct(t_gomoku *gomoku);
int readstandard(t_gomoku * gomoku);
int    run_cmd(t_gomoku *gomoku, char *str);
int    run_board(char *str);
int    run_start(t_gomoku *gomoku, char *str);
void    run_end(t_gomoku *gomoku, char *str);
int run_turn(t_gomoku *gomoku, char *str);
char    **my_str_to_word_array(char *str, char *lim);
int isnum(char *str);
char *board();
void init_struct(t_gomoku *gomoku);
int readstandard(t_gomoku * gomoku);
int my_intlen(int nb);
void invalid_string(void);
int nbr_coma(char *str);
int only_digit_str(char *str);
int check_players(char *str);
int check_coordinate(char *str);
int check_string(char *str);
char **my_str_to_word_array(char *str, char *delimiter);
int list_length(node_t *node);
int matching_node(char *str, node_t *node);
node_t *add_node(char *str, node_t *node);
void store_board(char *str);

#endif
