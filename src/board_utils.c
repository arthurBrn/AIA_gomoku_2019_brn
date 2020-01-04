/*
** EPITECH PROJECT, 2019
** run_board.c
** File description:
** run_board.c
*/

#include "gomoku.h"
#include "board.h"

void free_board_list(t_board *board)
{
    t_board *current = NULL;
    t_board *next = NULL;
    t_board *head_holder = board;

    while (board != NULL) {
        current = board;
        next = board->next;
        board = next;
        free(current);
    }
    free(next);
    free(head_holder);
    board = NULL;
}

void print_list(t_board *board)
{
    t_board *board_holder = board;

    if (board_holder == NULL)
        puts("NOTHING TO PRINT");
    while (board_holder != NULL)
    {
        printf("[current_head][x][y][player] => ");
        printf("%d", board_holder->x);
        putchar(',');
        printf("%d", board_holder->y);
        putchar(',');
        printf("%d", board_holder->player);
        putchar('\n');
        board_holder = board_holder->next;
    }
    board = board_holder;
}

void print_node(t_board *board) {
    printf("[current_head][x][y][player] => ");
    printf("%d, %d, %d\n", board->x, board->y, board->player);
}

int list_length(t_board *board)
{
    t_board *board_holder = board;
    int cpt = 0;

    for (; board_holder != NULL; cpt++)
        board_holder = board_holder->next;
    return (cpt);
}