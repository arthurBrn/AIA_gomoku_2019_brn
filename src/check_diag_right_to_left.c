/*
** EPITECH PROJECT, 2019
** check_diag_right_to_left.c
** File description:
** AIA_gomoku_2019
*/

#include "global.h"

int find_one_diag_rtol(t_gomoku *gomoku, int x, int y)
{
    node_t *temp = head;
    int count = 0;

    while (temp != NULL) {
        if (temp->x == x && temp->y == y)
            count = count_cons_diag_rtol(gomoku, x, y);
        temp = temp->next;
    }
    temp = head;
    return (count);
}

int check_second_half_rtol(t_gomoku *gomoku, int x, int y, int save_y)
{
    int count = 0;

    while (y <= gomoku->size) {
	    count = find_one_diag_rtol(gomoku, x, y);
	    x -= count + 1;
	    y += count + 1;
    }
    save_y -= 1;
    y = save_y;
    x = gomoku->size;
    if (y == 1)
	    return (0);
   return (check_second_half_rtol(gomoku, x, y, save_y));
}

int check_first_half_rtol(t_gomoku *gomoku, int x, int y, int save_x)
{
    int count = 0;

    while (x > 0) {
        count = find_one_diag_rtol(gomoku, x, y);
	    x -= count + 1;
        y += count + 1;
    }
    save_x++;
    x = save_x;
    y = 1;
    if (x > gomoku->size)
        return (0);
    return (check_first_half_rtol(gomoku, x, y, save_x));
}

int check_diag_right_to_left(t_gomoku *gomoku, int x, int y)
{
    check_first_half_rtol(gomoku, x, y, x);
    check_second_half_rtol(gomoku, gomoku->size, gomoku->size, gomoku->size);
    return (0);
}
