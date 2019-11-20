/*
** EPITECH PROJECT, 2019
** run_start.c
** File description:
** ..
*/

#include "gomoku.h"

int run_start(t_gomoku *gomoku, char *str) {

    if (gomoku->start == 1)
        return (puts(GAME_STARTED));
    if (str == NULL)
        puts(ERROR_MSG);
    else if (gomoku->start == 0 && isnum(str) != ERROR) {
        gomoku->size = atoi(str);
        if (gomoku->size == 0)
            return (puts(ERROR_MSG));
        puts(OK_MSG);
        gomoku->start = 1;
    } else
        puts(ERROR_MSG);
    return (0);
}
