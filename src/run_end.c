/*
** EPITECH PROJECT, 2019
** run_end.c
** File description:
** gomoku
*/

#include "gomoku.h"

int error_end(t_gomoku *gomoku)
{
    if (gomoku->start == 0) {
        write(1, GAME_NOT_STARTED, strlen(GAME_NOT_STARTED));
        return (MY_EXIT_FAILURE);
    }
    return (0);
}

int run_end(char *str, t_gomoku *gomoku)
{
    (void)str;
    if (error_end(gomoku) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    else {
        gomoku->end = 1;
        write(1, GAME_FINISH, strlen(GAME_FINISH));
        return (0);
    }
}
