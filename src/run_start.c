/*
** EPITECH PROJECT, 2019
** run_start.c
** File description:
** ..
*/

#include "gomoku.h"

int run_start(t_gomoku *gomoku, char *str) {

    if (gomoku->start == 1) {
        write(2, GAME_STARTED, strlen(GAME_STARTED));
        exit(84);
    }
    if (gomoku->start == 0 && isnum(str) != ERROR) {
        gomoku->size = atoi(str);
        if (gomoku->size == 0) {
            write(2, ERROR_MSG, strlen(ERROR_MSG));
            exit(84);
        }
        write(1, OK_MSG, strlen(OK_MSG));
        gomoku->start = 1;
    } else {
        write(2, ERROR_MSG, strlen(ERROR_MSG));
        exit(84);
    }
    return (0);
}
