/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** ..
*/

#include "gomoku.h"

void    readstandard()
{
    char    str[BUFF_SIZE];

    puts("Entre une commande");
    read(0, str, BUFF_SIZE);
}

int main(void)
{
    readstandard();
    return (0);
}
