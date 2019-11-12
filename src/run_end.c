/*
** EPITECH PROJECT, 2019
** run.end.c
** File description:
** ..
*/

#include "gomoku.h"

int run_end(t_gomoku *gomoku, char *str)
{
    if (strcmp("END", str) == 0) {
        if (gomoku->start == 0)
            puts("ERROR: The game didn't start.");
        else
            return (gomoku->end = 1, 0);
    }
    return (2);
}
