/*
** EPITECH PROJECT, 2019
** run_start.c
** File description:
** ..
*/

#include "gomoku.h"

void    run_start(t_gomoku *gomoku, char *str)
{
    if (strcmp("START", str) == 0) {
        if (gomoku->start == 0) {
            printf("OK - everything is good\n");
            gomoku->start = 1;
        }
	else
            printf("ERROR message - unsupported size or other error\n");
    }
}
