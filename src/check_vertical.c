/*
** EPITECH PROJECT, 2019
** check_vertical.c
** File description:
** AIA_gomoku_2019
*/

#include "global.h"

int count_vertical(t_gomoku *gomoku, int x, int y, node_t *head)
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

int find_one_vertical(t_gomoku *gomoku, int x, int y, node_t *head)
{
    int count = 0;

    for (int i = y; i < y + 5 && y <= gomoku->size; i++) {
        if (count_vertical(gomoku, x, i, head) == 1)
            count++;
        else {
            printf("vertical : %d\n", count);
            return (count);
        }
    }
    return (count);
}

int check_vertical(t_gomoku *gomoku, int x, int y)
{
    node_t *node = head;
    int cpt = 0;

    while (head != NULL) {
        if (head->x == x && head->y == y) {
            aligned = malloc(sizeof(aligned_t));
            aligned->player = head->player;
            y += find_one_vertical(gomoku, x, y, node);
	}
        head = head->next;
    }
    head = node;
    y++;
    if (y > gomoku->size) {
        y = 1;
        x++;
    }
    if (x == gomoku->size & y == gomoku->size)
        return (0);
    return (check_vertical(gomoku, x, y));
}
