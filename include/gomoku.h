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
#endif
