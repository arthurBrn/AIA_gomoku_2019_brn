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
void run_cmd(int (**tab_cmd)(char *, t_gomoku *));

char    **my_str_to_word_array(char *str, char *lim);
int isnum(char *str);

#endif
