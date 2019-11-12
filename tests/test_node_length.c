/*
** EPITECH PROJECT, 2019
** test_node_length
** File description:
** test function calulcating the length of the list
*/

#include <criterion/criterion.h>
#include <gomoku.h>

Test(list_length, test_no_length)
{
    node_t *head = NULL;
    int res = list_length(head);

    cr_assert_eq(res, 0);
}

Test(list_length, test_length_of_four)
{
    node_t *head = NULL;
    int i = 3;
    int res = 0;
    char str[4][8] =
    {
        "1,1,1",
        "2,2,2",
        "3,3,1",
        "4,4,2"
    };
    while (i >= 0) {
        head = add_node(str[i], head);
        i--;
    }
    res = list_length(head);

    cr_assert_eq(res, 4);
}
