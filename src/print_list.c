/*
** EPITECH PROJECT, 2019
** print_list.c
** File description:
** display all info of each nodes of the list
*/

#include "global.h"

void print_list(node_t *node)
{
    node_t *node_head = node;

    if (node_head == NULL)
        puts("NOTHING TO PRINT");
    while (node_head != NULL) {
        puts("[current_head][x][y][player] => ");
        putchar(node_head->x + '0');
        putchar(node_head->y + '0');
        putchar(node_head->player + '0');
        putchar('\n');
        node_head = node_head->next;
    }
}
