/*
** EPITECH PROJECT, 2019
** print_the_board
** File description:
** Display the board w/ every move made on it
*/

#include "gomoku.h"

int call_the_node(int x, int y, t_board *board)
{
    t_board *head = head;
    int flag = 0;

    while (board != NULL) {
        if (board->x == x && board->y == y && board->player == 1) {
            write(1, "o", 1);
            flag++;
        }
        if (board->x == x && board->y == y && (board->player == 2)) {
            write(1, "x", 1);
            flag++;
        }
        board = board->next;
    }
    free(board);
    board = NULL;
    return (flag);
}

void print_the_board(t_gomoku *gom, t_board *board)
{
    int size = gom->size * gom->size;
    int i = 0;
    int x = 1;
    int y = 1;

    while (size != 0) {
        if (call_the_node(x, y, board) != 1)
            write(1, "-", 1);
        size--;
        i++;
        x++;
        if (i == gom->size) {
            putchar('\n');
            i = 0;
            x = 1;
            y++;
        }
    }
}
