/*
** EPITECH PROJECT, 2019
** run_board.c
** File description:
** ..
*/

#include "global.h"

int run_board(t_gomoku *gomoku, char *s1) {
    (void) s1;
    ssize_t size = 0;
    char *str = "";

    if (gomoku->start == 0) {
        write(2, GAME_NOT_STARTED, strlen(GAME_NOT_STARTED));
        exit(ERROR);
    }
    while (strcmp(str, "DONE") != 0) {
        if ((str = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
            return (ERROR);
        if ((size = read(0, str, BUFF_SIZE)) < 0)
            return (ERROR);
        str[size - 1] = '\0';
        if (strcmp("DONE", str) != 0 && check_string(str, gomoku) == 1)
            store_board(str, gomoku);
        free(str);
    }
    return (0);
}
