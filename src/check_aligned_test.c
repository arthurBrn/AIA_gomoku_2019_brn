/*
** EPITECH PROJECT, 2019
** check_aligned.c
** File description:
** AIA_gomoku_2019
*/

#include "global.h"

int count_horizontal(t_gomoku *gomoku, int x, int y, node_t *head)
{
    int find = 0;
    node_t *temp = head;

    while (temp != NULL) {
	if (temp->x == x && temp->y ==y && aligned->player == temp->player)
	    find = 1;
	temp = temp->next;
    }
    return (find);
}

int find_one(t_gomoku *gomoku, int x, int y, node_t *head)
{
    int count = 0;
    
    for (int i = x; i < x + 5 && x < gomoku->size; i++) {
	if (count_horizontal(gomoku, i, y, head) == 1)
	    count++;
	else {
	    printf("horizontal : %d\n", count);
	    return (count);
	}
    }
    return (count);
}

aligned_t *init_block_player(aligned_t *tete, int player)
{
    aligned_t *temp = malloc(sizeof(aligned_t));

    temp = tete;
    temp->player = player;
    if (tete == NULL)
        temp->next = NULL;
    else
        temp->next = tete;
    return (temp);
}

int check_horizontal(t_gomoku *gomoku, int x, int y)
{
    node_t *node = head;
    aligned_t *al = NULL;
    int cpt = 0;

    while (head != NULL) {
	if (head->x == x && head->y == y) {
        aligned = init_block_player(aligned, head->player);
	    x += find_one(gomoku, x, y, node);
	}
	head = head->next;
    }
    head = node;
    x++;
    if (x > 10) {
	x = 1;
	y++;
    }
    if (x == 10 & y == 10)
	return (0);
    return (check_horizontal(gomoku, x, y));
}

int check_aligned(t_gomoku *gomoku)
{
    int x = 1;
    int y = 1;

    check_horizontal(gomoku, x, y);
    check_vertical(gomoku, x, y);
    return (0);
}