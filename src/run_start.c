/*
** EPITECH PROJECT, 2019
** run_start.c
** File description:
** ..
*/

#include "gomoku.h"

int run_start(t_gomoku *gomoku, char *str) {
    (void) str;

    if (gomoku->start == 1) {
        write(2, GAME_STARTED, strlen(GAME_STARTED));
        return (MY_EXIT_FAILURE);
    }
    if (gomoku->start == 0 && isnum(str) != MY_EXIT_FAILURE) {
        gomoku->size = atoi(str);
        if (gomoku->size == 0) {
            write(2, ERROR_MSG, strlen(ERROR_MSG));
            return (0);
        }
        write(1, OK_MSG, strlen(OK_MSG));
        gomoku->start = 1;
    } else {
        write(2, ERROR_MSG, strlen(ERROR_MSG));
        return (MY_EXIT_FAILURE);
    }
    free(str);
    return (0);
}
