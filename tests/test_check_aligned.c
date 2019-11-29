/*
** EPITECH PROJECT, 2019
** test_check_aligned.c
** File description:
** test function of file check aligned.c
*/

#include <criterion/criterion.h>
#include "global.h"

Test(count_horizontal, finding_x_y_in_linked_list)
{
    int res = 0;
    int i = 3;
    int x = 1;
    int y = 2;
    char str[4][8] = {"1,2,1", "2,2,2", "3,1,1", "4,1,2"};
    node_t *node = NULL;
    node_t *node_head = NULL;
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *align = malloc(sizeof(aligned_t));

    gom->size = 20;
    for (; i >= 0; i--)
        node_head = add_node(str[i], node_head);
    node = node_head;
    cr_assert_eq(list_length(node), 4);
    //cr_assert_not_null(node);
    res = count_horizontal(gom, x, y, node_head);
    cr_assert_eq(res, 1);
}