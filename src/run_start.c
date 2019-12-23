/*
** EPITECH PROJECT, 2019
** run_start.c
** File description:
** gomoku
*/

#include "gomoku.h"
#include "board.h"

int error_start(char *str, t_gomoku *gomoku)
{
    if (gomoku->start == 1) {
        write (2, GAME_STARTED, strlen(GAME_STARTED));
        return (MY_EXIT_FAILURE);
    }
    if (isnum(str) != 0) {
        write (2, ERROR_MSG, strlen(ERROR_MSG));
        return (MY_EXIT_FAILURE);
    }
    gomoku->size = atoi(str);
    if (gomoku->size == 0 || gomoku->size > 20 || gomoku->size < 5) {
        write (2, ERROR_MSG, strlen(ERROR_MSG));
        return (MY_EXIT_FAILURE);
    }   
    return (0);
}

t_board *init_board()
{
    t_board *board = malloc(sizeof(t_board));
    board->x = -1;
    board->y = -1;
    board->player = -1;
    board->next = NULL;
    return (board);
}

int run_start(char *str, t_gomoku *gomoku)
{
    if (error_start(str, gomoku) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    else {
        gomoku->start = 1;
        write (1, OK_MSG, strlen(OK_MSG));
        return (0);
    }
}
