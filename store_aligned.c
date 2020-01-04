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
            al = al->next;
        }
    }
}
