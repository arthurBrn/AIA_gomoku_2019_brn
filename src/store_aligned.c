/*
** EPITECH PROJECT, 2019
** store_aligned.c
** File description:
** AIA_gomoku_2019
*/

#include "global.h"


void initialize_block(int player, int initial_x, int initial_y)
{
    aligned_t *al = malloc(sizeof(aligned_t));

    al->start_x = initial_x;
    al->start_y = initial_y;
    al->player = player;
    al->end_x = 0;
    al->end_y = 0;
    al->len = 0;
    al->open = 0;
    if (aligned == NULL)
        al->next = NULL;
    else
        al->next = aligned;
    aligned = al;
}

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

int set_open_vertical(t_gomoku *gom)
{
    int left = 1;
    int right = 2;
    int open = 0;
    node_t *temp_head = head;
    aligned_t *temp_al = aligned;

    if (temp_al->start_y == 1)
        left = 0;
    if (temp_al->end_y == gom->size)
        right = 0;
    while (temp_head != NULL) {
        if (((temp_al->start_y - 1) == temp_head->y) && (temp_al->start_x == temp_head->x))
            left = 0;
        if (((temp_al->end_y + 1) == temp_head->y) && ((temp_al->start_x == temp_head->x)))
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

int aligned_length()
{
    aligned_t *al = aligned;
    int count = 0;

    if (al == NULL)
        return (0);
    while (al != NULL) {
        count++;
        al = al->next;
    }
    return (count);
}

void aligned_list_free()
{
    aligned_t *current = NULL;

    while (aligned != NULL) {
        current = aligned;
        aligned = aligned->next;
        free(current);
    }
    aligned = NULL;
}

void print_aligned()
{
    aligned_t *al = aligned;
    if (al == NULL)
        write(1, "nothing to print", 16);
    else {
        while (al != NULL) {
            write(1, "==========", 10);
            putchar('\n');
            printf("al->start_x : %d\n", al->start_x);
            printf("al->start_y : %d\n", al->start_y);
            printf("al->end_x : %d\n", al->end_x);
            printf("al->end_y : %d\n", al->end_y);
            printf("al->len : %d\n", al->len);
            printf("al->player : %d\n", al->player);
            printf("al->open : %d\n", al->open);
            al = al->next;
        }
    }
}