/*
** EPITECH PROJECT, 2019
** run_board.c
** File description:
** ..
*/

#include "global.h"

int run_board(t_gomoku *gomoku, char *str)
{
    ssize_t size;

    if (strcmp("BOARD", str) == 0) {
	while (strcmp(str, "DONE") != 0) {
            str = malloc(sizeof(char) * BUFF_SIZE);
            if ((size = read(0, str, BUFF_SIZE)) < 0)
		return (84);
            str[size - 1] = '\0';
            if (strcmp("DONE", str) != 0)
                store_board(str, gomoku);
            printf("str = <%s>\n", str);
	}
    }
    return (0);
}
