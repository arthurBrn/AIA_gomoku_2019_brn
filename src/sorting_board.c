/*
** EPITECH PROJECT, 2019
** run_board.c
** File description:
** run_board.c
*/ 

#include "gomoku.h"
#include "board.h"

void sort_board_per_x(t_board *board, char *search_direction)
{
    t_board *holder = board;

    if (strcmp(search_direction, "h") == 0) {
        while (holder->next != NULL) {
            if ((holder->x > holder->next->x) || ((holder->x == holder->next->x) && (holder->y < holder->next->y))) {
                swap(holder);
                holder = board;
            }

            else
                holder = holder->next;
        }
    }
    if (strcmp(search_direction, "v") == 0) {
        while (holder->next != NULL) {
            if ((holder->x < holder->next->x) || ((holder->x == holder->next->x) && (holder->y > holder->next->y))) {
                swap(holder);
                holder = board;
            }
            else
                holder = holder->next;
        }
    }
}

void sort_board_per_y(t_board *board, char *search_direction)
{
    t_board *hold = board;

    if (strcmp(search_direction, "h") == 0) {
        while (hold->next != NULL) {
            if ((hold->y < hold->next->y) || ((hold->y == hold->next->y) && (hold->x > hold->next->x))) {
                swap(hold);
                hold = board;
            }
            else
                hold = hold->next;
        }
    }
    if (strcmp(search_direction, "v") == 0) {
        while (hold->next != NULL) {
            if ((hold->x > hold->next->x) || ((hold->y == hold->next->y) && (hold->x > hold->next->x))) {
                swap(hold);
                hold = board;
            }
            else
                hold = hold->next;
        }
    }
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
    // holder = board;  
}