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
    char *str = {0};

    if (gomoku->start == 0)
        return (puts(GAME_NOT_STARTED));
    while (strcmp(str, "DONE") != 0) {
        str = malloc(sizeof(char) * BUFF_SIZE);
        if ((size = read(0, str, BUFF_SIZE)) < 0)
            return (ERROR);
        str[size - 1] = '\0';
        if (strcmp("DONE", str) != 0 && check_string(str, gomoku) == 1)
            store_board(str, gomoku);
        free(str);
    }
    return (0);
}
