/*
** EPITECH PROJECT, 2019
** invalid_string.c
** File description:
** Display error message and exit
*/

#include "gomoku.h"

void invalid_string(void)
{
    puts(ERROR_MSG);
    exit(EXIT_USAGE);
}
