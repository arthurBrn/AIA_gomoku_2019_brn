/*
** EPITECH PROJECT, 2019
** run_begin.c
** File description:
** AIA_gomoku_2019
*/

#include "gomoku.h"

int    run_begin(t_gomoku *gomoku, char *str) {
    (void)str;

    if (gomoku->start == 0)
        puts(GAME_NOT_STARTED);
    else
        gomoku->player = 1;
    return (0);
}
