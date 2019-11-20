/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** ..
*/

#include "gomoku.h"

int main(void)
{
    t_gomoku    *gomoku = malloc(sizeof(*gomoku));

    init_struct(gomoku);
    if (readstandard(gomoku) == ERROR)
        return (ERROR);
    return (0);
}
