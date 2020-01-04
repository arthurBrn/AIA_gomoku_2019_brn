/*
** EPITECH PROJECT, 2019
** check_aligned.c
** File description:
** AIA_gomoku_2019
*/

#include "global.h"

int count_horizontal(t_gomoku *gomoku, int x, int y, node_t *node)
{
    int find = 0;
    node_t *temp = node;

    while (temp != NULL) {
	    if (temp->x == x && temp->y == y && aligned->player == temp->player)
	        find = 1;
	    temp = temp->next;
    }
    return (find);
}

int find_one(t_gomoku *gomoku, int x, int y, node_t *node)
{
    int count = 0;
    
    for (int i = x; i < x + 5 && x <= gomoku->size; i++) {
	    if (count_horizontal(gomoku, i, y, node) == 1)
	        count++;
	    else {
	        return (count);
	    }
    }
    return (count);
}

int check_horizontal(t_gomoku *gomoku, int x, int y)
{
    node_t *node = head;
    node_t *temp_head = head;

    while (node != NULL) {
	    if (node->x == x && node->y == y) {
	        initialize_block(node->player, node->x, node->y);
            set_len_horizontal(find_one(gomoku, x, y, temp_head), gomoku);
	        x = x + find_one(gomoku, x, y, temp_head);
	    }
	    node = node->next;
    }
    x++;
    if (x > gomoku->size) {
	    x = 1;
	    y++;
    }
    if (x == gomoku->size & y == gomoku->size)
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