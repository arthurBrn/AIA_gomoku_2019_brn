/*
** EPITECH PROJECT, 2019
** make_move.c
** File description:
** Used to make a move
*/

#include "global.h"

aligned_t *find_best_move()
{
    aligned_t *al = NULL;
    aligned_t *temp = NULL;
    int cpt = 0;
    int open = 0;

    al = aligned;
    while (al != NULL) {
        // modify it to add open here
        if ((al->len >= cpt) && (al->open >= open)) {
            cpt = al->len;
            open = al->open;
            temp = al;
        }
        al = al->next;
    }
    return (temp);
}

void make_move()
{
    aligned_t *move = NULL;

    move = find_best_move();
    print_aligned();
}

