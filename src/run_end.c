/*
** EPITECH PROJECT, 2019
** run.end.c
** File description:
** ..
*/

#include "gomoku.h"

void    run_end(t_gomoku *gomoku, char *str)
{
    if (strcmp("END", str) == 0)
	gomoku->end = 1;
}
