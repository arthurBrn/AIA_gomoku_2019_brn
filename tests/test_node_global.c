/*
** EPITECH PROJECT, 2019
** test_node_global.c
** File description:
** Test the global var node_t *head
*/

#include "global.h"
#include <criterion/criterion.h>

Test(store_board, test_creation_five_nodes)
{
    int res = 0;
    t_gomoku *gomoku = malloc(sizeof(t_gomoku));

    gomoku->size = 10;
    store_board("1,1,2", gomoku);
    store_board("1,2,1", gomoku);
    store_board("2,2,2", gomoku);
    store_board("3,4,1", gomoku);
    store_board("5,6,2", gomoku);
    res = list_length(head);

    cr_assert_eq(res, 5);
}
