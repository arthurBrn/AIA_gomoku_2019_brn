/*
** EPITECH PROJECT, 2019
** run_start.c
** File description:
** ..
*/

#include "global.h"

int run_start(t_gomoku *gomoku, char *str) {
    (void) str;

    if (gomoku->start == 1) {
        write(2, GAME_STARTED, strlen(GAME_STARTED));
        return (ERROR);
    }
    if (gomoku->start == 0 && isnum(str) != ERROR) {
        gomoku->size = atoi(str);
        if (gomoku->size == 0) {
            write(2, ERROR_MSG, strlen(ERROR_MSG));
            return (ERROR);
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
	print_list(head);
	gomoku->start = 1;
    } else {
        write(2, ERROR_MSG, strlen(ERROR_MSG));
        return (ERROR);
    }
    free(str);
    return (0);
}
