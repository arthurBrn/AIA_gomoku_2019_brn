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

int find_one(t_gomoku *gomoku, int x, int y, node_t *head)
{
    int count = 0;
    
    for (int i = x; i < x + 5 && x <= gomoku->size; i++) {
	    if (count_horizontal(gomoku, i, y, head) == 1)
	        count++;
	    else {
	        printf("horizontal : %d\n", count);
	        return (count);
	    }
    }
    return (count);
}

int check_horizontal(t_gomoku *gomoku, int x, int y)
{
    node_t *node = head;
    int hold_x = 0;

    while (head != NULL) {
	    if (head->x == x && head->y == y) {
	        initialize_block(head->player, head->x, head->y);
            set_len(find_one(gomoku, x, y, node));
	        x = x + find_one(gomoku, x, y, node);
	    }
	    head = head->next;
    }
    set_final_x_y();
    head = node;
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

    if (aligned != NULL)
        aligned_list_free();
    check_horizontal(gomoku, x, y);
    print_aligned();
    //check_vertical(gomoku, x, y);
    //print_aligned();
    aligned_list_free();
    return (0);
}
