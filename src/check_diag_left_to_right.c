/*
** EPITECH PROJECT, 2019
** check_diag_left_to_rifht.c
** File description:
** AIA_gomoku_2019
*/

#include "global.h"

int find_one_diag_ltor(t_gomoku *gomoku, int x, int y)
{
    node_t *temp = head;
    int count = 0;

    while (temp != NULL) {
	if (temp->x == x && temp->y == y)
	    count = count_cons_diag_ltor(gomoku, x, y);
	temp = temp->next;
    }
    temp = head;
    return (count);
}

int check_first_half_ltor(t_gomoku *gomoku, int x, int y, int save_x)
{
    int count = 0;

    while (x <= gomoku->size) {
	count = find_one_diag_ltor(gomoku, x, y);
	x += count + 1;
	y += count + 1;
    }
    save_x--;
    x = save_x;
    y = 1;
    if (x == 0)
	return (0);
    return (check_first_half_ltor(gomoku, x, y, save_x));
}

int check_second_half_ltor(t_gomoku *gomoku, int x, int y, int save_y)
{
    int count = 0;

    while (y <= gomoku->size) {
	count = find_one_diag_ltor(gomoku, x, y);
	x += count + 1;
	y += count + 1;
    }
    save_y--;
    y = save_y;
    x = 1;
    if (y == 1)
	return (0);
    return check_second_half_ltor(gomoku, x, y, save_y);;
}

int check_diag_left_to_right(t_gomoku *gomoku, int x, int y)
{
    int save_x = x;

    check_first_half_ltor(gomoku, x, y, save_x);
    x = 1;
    check_second_half_ltor(gomoku, x, y, gomoku->size);
    return (0);
}
