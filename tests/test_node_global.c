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
    int i = 0;
    char *str = "1,2,2";
    int res = 0;

    while (i != 5) {
        store_board(str);
        i++;
    }
    res = list_length(head);
    cr_assert_eq(res, 5);
}
