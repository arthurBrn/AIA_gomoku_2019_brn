/*
** EPITECH PROJECT, 2019
** run_begin.c
** File description:
** gomoku
*/

#include "gomoku.h"
#include "board.h"

int error_begin(t_gomoku *gomoku)
{
    if (gomoku->start == 0) {
        write(2, GAME_NOT_STARTED, strlen(GAME_NOT_STARTED));
        return (MY_EXIT_FAILURE);
    }
    if (gomoku->begin == 1)
        return (MY_EXIT_FAILURE);
    return (0);
}

int run_begin(char *str, t_gomoku *gomoku)
{
    (void) str;
    int play;
    
    if (error_begin(gomoku) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    else {
        gomoku->begin = 1;
        play = gomoku->size / 2;
        write(1, itoa(play), strlen(itoa(play)));
        write(1, ",", 1);
        write(1, itoa(play), strlen(itoa(play)));
        return (0);
    }
}
