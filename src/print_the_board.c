/*
** EPITECH PROJECT, 2019
** print_the_board
** File description:
** Display the board w/ every move made on it
*/

#include "global.h"

int call_the_node(int x, int y)
{
    node_t *node = head;
    int flag = 0;

    while (node != NULL) {
        if (node->x == x && node->y == y && node->player == 1) {
            write(1, "o", 1);
            flag++;
        }
        if (node->x == x && node->y == y && (node->player == 2)) {
            write(1, "x", 1);
            flag++;
        }
        node = node->next;
    }
    return (flag);
}

void print_the_board(t_gomoku *gom)
{
    int size = gom->size * gom->size;
    int i = 0;
    int x = 1;
    int y = 1;

    while (size != 0) {
        if (call_the_node(x, y) != 1)
            write(1, "-", 1);
        size--;
        i++;
        //y++;
        x++;
        if (i == gom->size) {
            putchar('\n');
            i = 0;
            //x++;
            x = 1;
            //y = 1;
            y++;
        }
    }
}