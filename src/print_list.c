/*
** EPITECH PROJECT, 2019
** print_list.c
** File description:
** display all info of each nodes of the list
*/

#include "global.h"

void print_list(node_t *head)
{
    if (head == NULL)
        puts("NOTHING TO PRINT");
    while (head != NULL) {
        puts("[current_head][x][y][player] => ");
        putchar(head->x + '0');
        putchar(head->y + '0');
        putchar(head->player + '0');
        putchar('\n');
        head = head->next;
    }
}
