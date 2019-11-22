/*
** EPITECH PROJECT, 2019
** run_begin.c
** File description:
** AIA_gomoku_2019
*/

#include "gomoku.h"

int    run_begin(t_gomoku *gomoku, char *str) {

    if (gomoku->player == 1) {
        write(2, ERROR_MSG, strlen(ERROR_MSG));
        exit(84);
    }
    if (gomoku->start == 0) {
        write(2, GAME_NOT_STARTED, strlen(GAME_NOT_STARTED));
        exit(84);
    }
    if (strcmp(str, "") != 0) {
        write(2, ERROR_MSG, strlen(ERROR_MSG));
        exit(84);
    }
    else
        gomoku->player = 1;
    return (0);
}
