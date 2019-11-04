/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** ..
*/

#include "gomoku.h"

int isnum(char *str)
{
    for (int i = 0; (str[i]); i++)
        if (isdigit(str[i]) == 0)
            return (84);
    return (0);
}
