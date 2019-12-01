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
        free_board_list();
        return (MY_EXIT_FAILURE);
    }
    free_board_list();
    return (0);
}
