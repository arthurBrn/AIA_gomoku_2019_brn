/*
** EPITECH PROJECT, 2019
** run_begin.c
** File description:
** AIA_gomoku_2019
*/

#include "gomoku.h"

int run_begin(t_gomoku *gomoku, char *str)
{
    if (strcmp("BEGIN", str) == 0 && gomoku->player == 0)
        gomoku->player = 1;
    return (0);
}
