/*
** EPITECH PROJECT, 2019
** run.end.c
** File description:
** ..
*/

#include "gomoku.h"

int run_end(t_gomoku *gomoku, char *str) {
    (void) str;

    if (gomoku->start == 0)
        puts(GAME_NOT_STARTED);
    else
        gomoku->end = 1;
    return (0);
}
