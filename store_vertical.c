/*
** EPITECH PROJECT, 2019
** store_vertical.c
** File description:
** Store all vertical suits
*/

#include "global.h"

int set_open_vertical(t_gomoku *gom)
{
    int top = 1;
    int bottom = 2;
    int open = 0;
    node_t *temp_head = head;
    aligned_t *temp_al = aligned;

    if (temp_al->start_y == 1)
        top = 0;
    if (temp_al->end_y == gom->size)
        bottom = 0;
    while (temp_head != NULL) {
        if (((temp_al->start_y - 1) == temp_head->y) && (temp_al->start_x == temp_head->x))
            top = 0;
        if (((temp_al->end_y + 1) == temp_head->y) && (temp_al->start_x == temp_head->x))
            bottom = 0;
        temp_head = temp_head->next;
    }
    open = top + bottom;
    return (open);
}

void set_final_x_y_vertical()
{
    if (aligned->len == 1)
        aligned->end_y = aligned->start_y;
    else 
        aligned->end_y = ((aligned->start_y + aligned->len) - 1);
    aligned->end_x = aligned->start_x;
}

void set_len_vertical(int length, t_gomoku *gom)
{
    aligned->len = length;
    set_final_x_y_vertical();
    aligned->open = set_open_vertical(gom);
}