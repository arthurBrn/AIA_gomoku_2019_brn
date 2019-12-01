/*
** EPITECH PROJECT, 2019
** store_diagonal
** File description:
** Store all diagonale suits
*/

#include "global.h"


//int set_open_diagonal(t_gomoku *gom)
int set_open_diagonal()
{
    int top = 1;
    int bottom = 2;
    int open = 0;
    node_t *temp_head = head;
    aligned_t *temp_al = aligned;

    if (temp_al->start_y == 1)
        top = 0;
    if (temp_al->end_y == temp_al->start_x)
        bottom = 0;
    while (temp_head != NULL && (top != 0 && bottom != 0)) {
        if (((temp_al->start_y - 1) == temp_head->y) && ((temp_al->start_x + 1) == temp_head->x))
            top = 0;
        if (((temp_al->end_y + 1) == temp_head->y) && ((temp_al->start_x - 1) == temp_head->x))
            bottom = 0;
        temp_head = temp_head->next;
    }
    open = top + bottom;
    return (open);
}

void set_final_x_y_diagonal()
{
    if (aligned->len == 1)
        aligned->end_y = aligned->start_y;
    else
        aligned->end_y = ((aligned->start_y + aligned->len) - 1);
    aligned->end_x = ((aligned->start_x - aligned->len) + 1);
}

void set_len_diagonal(int length, t_gomoku *gom)
{
    aligned->len = length;
    set_final_x_y_diagonal();
    aligned->open = set_open_diagonal(gom);
    printf("%s", "DIAG");
    printf("%d", aligned->open);
}