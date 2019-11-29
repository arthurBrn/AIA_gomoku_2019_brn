/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** ..
*/

#include "global.h"

int main(void)
{
    if (gomoku() == MY_EXIT_FAILURE) {
        free_list(head);
        return (MY_EXIT_FAILURE);
    }
    free_list(head);
    return (0);
}
