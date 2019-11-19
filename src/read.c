/*
** EPITECH PROJECT, 2019
** read.c
** File description:
** ..
*/

#include "gomoku.h"

void    init_struct(t_gomoku *gomoku)
{
    gomoku->start = 0;
    gomoku->player  = 0;
    gomoku->end = 0;
    gomoku->size = 20;
}

int readstandard(t_gomoku * gomoku)
{
    char    *str = NULL;
    ssize_t size;

    while (gomoku->end != 1) {
        str = malloc(sizeof(char) * BUFF_SIZE);
        if ((size = read(0, str, BUFF_SIZE)) < 0)
            return (84);
        str[size - 1] = '\0';
        run_cmd(gomoku, str);
        free(str);
    }
    return (0);
}
