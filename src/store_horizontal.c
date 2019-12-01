/*
** EPITECH PROJECT, 2019
** store_horizontal.c
** File description:
** store all horizontal suits
*/

#include "global.h"

int set_open_horizontal(t_gomoku *gom)
{
    int left = 1;
    int right = 2;
    int open = 0;
    node_t *temp_head = head;
    aligned_t *temp_al = aligned;

    if (temp_al->start_x == 1)
        left = 0;
    if (temp_al->end_x == gom->size)
        right = 0;
    while (temp_head != NULL) {
        if (((temp_al->start_x - 1) == temp_head->x) && (temp_al->start_y == temp_head->y))
            left = 0;
        if (((temp_al->end_x + 1) == temp_head->x) && ((temp_al->start_y == temp_head->y)))
            right = 0;
        temp_head = temp_head->next;
    }
    open = left + right;
    return (open);
}

void set_final_x_y_horizontal()
{
    if (aligned->len == 1)
        aligned->end_x = aligned->start_x;
    else 
        aligned->end_x = ((aligned->start_x + aligned->len) - 1);
    aligned->end_y = aligned->start_y;
}

void set_len_horizontal(int length, t_gomoku *gom)
{
    aligned->len = length;
    set_final_x_y_horizontal();
    aligned->open = set_open_horizontal(gom);
}