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
	store_board("4,2,2", gomoku);
        store_board("5,2,2", gomoku);
	store_board("6,2,2", gomoku);
	store_board("7,2,2", gomoku);
	store_board("10,1,2", gomoku);
        store_board("10,2,2", gomoku);
	store_board("10,3,2", gomoku);
        store_board("10,4,2", gomoku);
	store_board("4,5,2", gomoku);
	store_board("5,6,2", gomoku);
	store_board("6,7,2", gomoku);
        store_board("7,8,2", gomoku);
	store_board("7,5,2", gomoku);
	store_board("6,6,2", gomoku);
	store_board("5,7,2", gomoku);
	store_board("4,8,2", gomoku);
 	gomoku->start = 1;
    } else {
        write(2, ERROR_MSG, strlen(ERROR_MSG));
        return (MY_EXIT_FAILURE);
    }
    return (0);
}
