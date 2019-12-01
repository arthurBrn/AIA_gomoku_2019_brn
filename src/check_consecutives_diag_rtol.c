/*
** EPITECH PROJECT, 2019
** check_consecutives_diag_rtol.c
** File description:
** AIA_gomoku_2019
*/

#include "global.h"

int check_next_diag_rtol(t_gomoku *gomoku, int x, int y)
{
    node_t *temp = head;
    int find = 0;

    while (temp != NULL) {
        if (temp->x == x && temp->y == y)
            find = 1;
        temp = temp->next;
    }
    return (find);
}

int count_cons_diag_rtol(t_gomoku *gomoku, int x, int y)
{
    int i = x;
    int j = y;
    int max = gomoku->size;
    int count = 0;

    while (i < x + 5 && j < y + 5 && i <= max && j <= max && i > 0 && j > 0) {
        if (check_next_diag_rtol(gomoku, i, j) == 1)
            count++;
        else {
            printf("diag rtol : %d\n", count);
            return (count);
        }
	i--;
	j++;
    }
    printf("diag rtol : %d\n", count);
    return (count);
}