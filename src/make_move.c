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

    al = aligned;
    while (al != NULL) {
        if (al->len > cpt) {
            cpt = al->len;
            temp = al;
        }
        al = al->next;
    }
    return (temp);
}