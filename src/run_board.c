/*
** EPITECH PROJECT, 2019
** run_board.c
** File description:
** ..
*/

#include "global.h"

int run_board(t_gomoku *gomoku, char *s1)
{
    ssize_t size = 0;
    char *str = "";

    if (gomoku->start == 0)
        return (write(2, GAME_NOT_STARTED, strlen(GAME_NOT_STARTED)), MY_EXIT_FAILURE);
    if (strcmp(s1, "") != 0)
        return (write(2, ERROR_MSG, strlen(ERROR_MSG)), MY_EXIT_FAILURE);
    while (strcmp(str, "DONE") != 0) {
        if ((str = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
            return (MY_EXIT_FAILURE);
        if ((size = read(0, str, BUFF_SIZE)) < 0)
            return (MY_EXIT_FAILURE);
        str[size - 1] = '\0';
        if (strcmp("DONE", str) == 0)
            return (0);
        else if (store_board(str, gomoku) == 84) {
            write(1, ERROR_SIZE, strlen(ERROR_SIZE));
            return (MY_EXIT_FAILURE);
        }
        free(str);
    }
    return (0);
}
