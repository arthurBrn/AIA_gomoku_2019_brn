/*
** EPITECH PROJECT, 2019
** test_node_creation.c
** File description:
** Test all function related to linked list
*/

#include <criterion/criterion.h>
#include "gomoku.h"

Test(add_node, test_add_node_valid_str)
{
    char *str = "10,10,1";
    node_t *head = NULL;
    node_t *element = add_node(str, head);

    cr_assert_eq(element->x, 10);
    cr_assert_eq(element->y, 10);
    cr_assert_eq(element->player, 1);
}

Test(add_node, test_add_multiple_node_in_a_row)
{
    int i = 3;
    int j = 0;
    node_t *head = NULL;
    char **str;
    char tab[4][8] =
        {
            "1,1,1",
            "2,2,2",
            "3,3,1",
            "4,4,2"
        };

    while (i >= 0) {
        head = add_node(tab[i], head);
        i--;
    }
    while (head != NULL) {
        str = my_str_to_word_array(tab[j], ",");
        cr_assert_eq(head->x, atoi(str[0]));
        cr_assert_eq(head->y, atoi(str[1]));
        cr_assert_eq(head->player, atoi(str[2]));
        head = head->next;
        j++;
    }
    cr_assert_eq(list_length(head), 4);
}
