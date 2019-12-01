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
        printf("[current_head][x][y][player] => ");
        printf("%d",node_head->x);
        putchar(',');
        printf("%d",node_head->y);
        putchar(',');
        printf("%d", node_head->player);
        putchar('\n');
        node_head = node_head->next;
    }
}
