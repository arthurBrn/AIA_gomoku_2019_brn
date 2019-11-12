/*
** EPITECH PROJECT, 2019
** test_node_matching_nodes.c
** File description:
** test function matching nodes
*/

#include <criterion/criterion.h>
#include "gomoku.h"

Test(matching_nodes, test_matching_nodes)
{
    node_t *head = NULL;
    int i = 2;
    int res = 0;
    char *src = "1,1,1";
    char str[3][8] = {"1,1,1","2,2,2","3,3,1"};

    while (i >= 0) {
        head = add_node(str[i], head);
        i--;
    }
    res = matching_node(src, head);
    cr_assert_eq(res, 0);
}

Test(matching_nodes, test_none_matching_nodes)
{
    node_t *head = NULL;
    int i = 2;
    int res = 0;
    char *src = "1,1,2";
    char str[3][8] = {"1,1,1","2,2,2","3,3,1"};

    while (i >= 0) {
        head = add_node(str[i], head);
        i--;
    }
    res = matching_node(src, head);
    cr_assert_eq(res, 1);
}
