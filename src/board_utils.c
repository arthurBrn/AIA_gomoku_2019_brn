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

    while (board != NULL)
    {
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
    int i = 0;

    if (board_holder == NULL)
        puts("NOTHING TO PRINT");
    printf("%s %d\n", "List size : ", list_length(board));
    while (board_holder != NULL)
    {
        putchar(i + '0');
        printf("[current_head][x][y][player] => ");
        printf("%d", board_holder->x);
        putchar(',');
        printf("%d", board_holder->y);
        putchar(',');
        printf("%d", board_holder->player);
        putchar('\n');
        board_holder = board_holder->next;
        i++;
    }
    board = board_holder;
}

// void print_node(t_board *board) {
//     printf("[current_head][x][y][player] => ");
//     printf("%d, %d, %d\n", board->x, board->y, board->player);
// }

int list_length(t_board *board)
{
    t_board *board_holder = board;
    int cpt = 0;

    for (; board_holder != NULL; cpt++)
        board_holder = board_holder->next;
    return (cpt);
}

void swap(t_board *holder)
{
    int x_holder = 0;
    int y_holder = 0;
    int p_holder = 0;

    x_holder = holder->x;
    y_holder = holder->y;
    p_holder = holder->player;

    holder->x = holder->next->x;
    holder->y = holder->next->y;
    holder->player = holder->next->player;

    holder->next->x = x_holder;
    holder->next->y = y_holder;
    holder->next->player = p_holder;
}

void sort_board_per_x(t_board *board, char search_direction)
{
    t_board *holder = board;

    while (holder->next != NULL) {
        if ((holder->x > holder->next->x) || ((holder->x == holder->next->x) && (holder->y < holder->next->y))) {
            swap(holder);
            holder = board;
        }
        else {
            holder = holder->next;
        }
    }
}

void sort_board_per_y(t_board *board, char search_direction)
{
    t_board *hold = board;
    // (void)search_direction;

    while (hold->next != NULL) {
        if (search_direction == 'h' && ((hold->y < hold->next->y) || ((hold->y == hold->next->y) && (hold->x > hold->next->x)))) {
            swap(hold);
            hold = board;
        } else if (search_direction == 'v' && ((hold->y > hold->next->y) || ((hold->y == hold->next->y) && (hold->x < hold->next->x)))) {
            swap(hold);
            hold = board;
        }
        else {
            hold = hold->next;
        }


        // else if ( search_direction == 'v' && ((hold->y < hold->next->y) || ((hold->y == hold->next->y) && (hold->x > hold->next->x)))) {
            // swap(hold);
            // hold = board;
        // } 
    }
}