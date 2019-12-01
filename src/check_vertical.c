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
    node_t *temp_head = head;

    while (node != NULL) {
        if (node->x == x && node->y == y) {
            initialize_block(node->player, node->x, node->y);
            set_len_vertical(find_one_vertical(gomoku, x, y, temp_head), gomoku);
            y = y + find_one_vertical(gomoku, x, y, temp_head);
	    }
        node = node->next;
    }
    y++;
    if (y > gomoku->size) {
        y = 1;
        x++;
    }
    if ((x == gomoku->size) & (y == gomoku->size))
        return (0);
    return (check_vertical(gomoku, x, y));
}
