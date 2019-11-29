/*
** EPITECH PROJECT, 2019
** run_start.c
** File description:
** ..
*/

#include "global.h"

int run_start(t_gomoku *gomoku, char *str)
{
    if (gomoku->start == 1) {
        write(2, GAME_STARTED, strlen(GAME_STARTED));
        return (MY_EXIT_FAILURE);
    }
    if (gomoku->start == 0 && isnum(str) != MY_EXIT_FAILURE) {
        gomoku->size = atoi(str);
        if (gomoku->size == 0) {
            write(2, ERROR_MSG, strlen(ERROR_MSG));
            return (0);
        }
        write(1, OK_MSG, strlen(OK_MSG));
	store_board("2,1,2", gomoku);
	store_board("3,1,2", gomoku);
        store_board("4,1,2", gomoku);
        store_board("2,3,2", gomoku);
        store_board("3,3,2", gomoku);
        store_board("7,3,2", gomoku);
        store_board("8,3,2", gomoku);
        store_board("5,5,2", gomoku);
        store_board("6,5,2", gomoku);
        store_board("2,8,2", gomoku);
        store_board("3,10,2", gomoku);
        store_board("4,10,2", gomoku);
        store_board("6,10,2", gomoku);
        store_board("7,10,2", gomoku);
	store_board("3,4,1", gomoku);
        store_board("4,4,1", gomoku);
        store_board("3,7,1", gomoku);
	store_board("4,7,1", gomoku);
        store_board("5,7,1", gomoku);
	gomoku->start = 1;
    } else {
        write(2, ERROR_MSG, strlen(ERROR_MSG));
        return (MY_EXIT_FAILURE);
    }
    return (0);
}
