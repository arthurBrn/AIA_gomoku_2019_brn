/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** ..
*/

#include "gomoku.h"

void    init_struct(t_gomoku *gomoku)
{
    gomoku->start = 0;
    gomoku->end = 0;
}

int readstandard(t_gomoku * gomoku)
{
    char    *str = NULL;
    ssize_t size;
    
    while (gomoku->end != 1) {
        str = malloc(sizeof(char) * BUFF_SIZE);
        puts("The manager sends:");
        if ((size = read(0, str, BUFF_SIZE)) < 0)
            return (84);
        str[size - 1] = '\0';
        if (run_cmd(gomoku, str) == 84)
            return (84);
        free(str);
    }
    return (0);
}

int main(void)
{
    t_gomoku    *gomoku = malloc(sizeof(gomoku));

    init_struct(gomoku);
    if (readstandard(gomoku) == 84)
        return (84);
    return (0);
}
