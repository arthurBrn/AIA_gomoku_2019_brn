/*
** EPITECH PROJECT, 2019
** check_consecutives_diag_ltor.c
** File description:
** AIA_gomoku_2019
*/

#include "global.h"

int check_next_diag_ltor(t_gomoku *gomoku, int x, int y, node_t *node)
{
    node_t *temp = head;
    int find = 0;

    while (temp != NULL) {
	if (temp->x == x && temp->y == y && temp->player == aligned->player)
	    find = 1;
	temp = temp->next;
    }
    return (find);
}

int count_cons_diag_ltor(t_gomoku *gomoku, int x, int y, node_t *node)
{
    int i = x;
    int j = y;
    int max = gomoku->size;
    int count = 0;

    while (i < x + 5 && j < y + 5 && i <= max && j <= max) {
	if (check_next_diag_ltor(gomoku, i, j, node) == 1)
	    count++;
	else {
	    printf("diag ltor : %d\n", count);
	    return (count);
	}    
	i++;
	j++;
    }
    printf("diag ltor : %d\n", count);
    return (count);
}
