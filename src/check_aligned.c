/*
** EPITECH PROJECT, 2019
** turn.c
** File description:
** AIA_gomoku_2019
*/

#include "global.h"

int get_min_y(t_gomoku *gomoku)
{
    int min_y = head->y;
    node_t *node = head;

    while (head != NULL) {
	if (head->y < min_y && gomoku->player == head->player)
	    min_y = head->y;
	head = head->next;
    }
    head = node;
    printf("head X: %d\n", head->x);
    printf("head Y: %d\n", head->y);
    return (min_y);
}

int get_min_x(t_gomoku *gomoku, int y)
{
    int min_x = head->x;

    while (head != NULL) {
	if (gomoku->player == head->player && y == head->y )
	    printf("all x : %d\n", head->x);
	    min_x = head->x;
    }
    return (min_x);
}

int check_horizontal(t_gomoku *gomoku)
{
    int y = get_min_y(gomoku);
    int x = get_min_x(gomoku, y);

    printf("y : %d\n", y);
    //printf("x : %d\n", x);
    return (0);
}

int check_aligned(t_gomoku *gomoku)
{
    check_horizontal(gomoku);
    return (0);
}
