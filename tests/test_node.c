/*
** EPITECH PROJECT, 2019
** test_node.c
** File description:
** Test all function related to linked list
*/

#include <criterion/criterion.h>
#include "node_proto.h"

Test(create_node, test_list_creation)
{
    char *x = "10";
    char *y = "11";
    char *player = "1";
    char *str = "10,10,1";

    // Launch creation function
    // Store the resulf of it which is the head

    cr_assert_str_eq(element->x, 10);
    cr_assert_str_eq(element->y, 10);
    cr_assert_str_eq(element->player, 1);
}
