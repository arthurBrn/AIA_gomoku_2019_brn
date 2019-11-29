/*
** EPITECH PROJECT, 2019
** run.end.c
** File description:
** ..
*/

#include "gomoku.h"

int run_end(t_gomoku *gomoku, char *str) {
    (void)str;
    if (gomoku->start == 0) {
        write(2, GAME_NOT_STARTED, strlen(GAME_NOT_STARTED));
        return (MY_EXIT_FAILURE);
    }
    else {
        write(1, GAME_FINISH, strlen(GAME_FINISH));
        gomoku->end = 1;
    }
    return (0);
}
