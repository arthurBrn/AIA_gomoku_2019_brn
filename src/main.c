/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** ..
*/

#include "global.h"

int main(void)
{
    if (readstandard() == ERROR) {
//        free_list(head);
        return (ERROR);
    }
    print_list(head);
    return (0);
}
