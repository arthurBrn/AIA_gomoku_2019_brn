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

        store_board("3,1,1", gomoku);
        store_board("4,1,1", gomoku);
        store_board("2,3,2", gomoku);
        store_board("3,3,2", gomoku);
        store_board("4,3,2", gomoku);
        store_board("1,5,2", gomoku);
        store_board("2,5,2", gomoku);

        /*store_board("1,3,2", gomoku);
        store_board("1,4,2", gomoku);
        store_board("3,2,2", gomoku);
        store_board("3,3,2", gomoku);
        store_board("3,4,2", gomoku);
        store_board("5,1,2", gomoku);
        store_board("5,2,2", gomoku);*/

/*
	store_board("2,2,2", gomoku);
        store_board("2,3,2", gomoku);
        store_board("2,4,2", gomoku);
        store_board("3,2,2", gomoku);
        store_board("3,9,2", gomoku);
        store_board("4,2,2", gomoku);
        store_board("4,6,2", gomoku);
	store_board("4,7,2", gomoku);
        store_board("6,2,2", gomoku);
        store_board("6,3,2", gomoku);
	store_board("6,4,2", gomoku);
        store_board("6,5,2", gomoku);
	store_board("6,10,2", gomoku);
        store_board("7,8,2", gomoku);
        store_board("8,2,2", gomoku);
        store_board("8,3,2", gomoku);
	store_board("8,5,2", gomoku);
        store_board("8,6,2", gomoku);
	store_board("8,7,2", gomoku);
*/
        print_the_board(gomoku);
	gomoku->start = 1;
    } else {
        write(2, ERROR_MSG, strlen(ERROR_MSG));
        return (MY_EXIT_FAILURE);
    }
    return (0);
}
