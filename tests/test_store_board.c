/*
** EPITECH PROJECT, 2019
** test_store_board.c
** File description:
** test all function of file store_board.c
*/

#include <criterion/criterion.h>
#include "global.h"

Test(list_length, test_no_length)
{
    node_t *head = NULL;
    int res = list_length(head);

    cr_assert_eq(res, 0);
}

Test(list_length, test_length_of_four)
{
    node_t *node = NULL;
    node_t *head = NULL;
    int i = 3;
    int res = 0;
    char str[4][8] = {"1,1,1", "2,2,2", "3,3,1", "4,4,2"};

    for (; i >= 0; i--)
        head = add_node(str[i], head);
    node = head;
    res = list_length(head);
    cr_assert_eq(res, 4);
    cr_assert_eq(head, node);
}

Test(matching_nodes, same_player_playing_at_same_pos)
{
    node_t *head = NULL;
    int i = 2;
    int res = 0;
    char *src = "1,1,1";
    char str[3][8] = {"1,1,1","2,2,2","3,3,1"};

    for (; i >= 0; i--)
        head = add_node(str[i], head);
    res = matching_node(src, head);
    cr_assert_eq(res, MY_EXIT_FAILURE);
}

Test(matching_nodes, diff_player_playing_at_same_pos)
{
    node_t *head = NULL;
    node_t *temp = NULL;
    int i = 2;
    int res = 0;
    char *src = "1,1,2";
    char str[3][8] = {"1,1,1","2,2,2","3,3,1"};

    for (; i >= 0; i--)
        head = add_node(str[i], head);
    temp = head;
    res = matching_node(src, head);
    cr_assert_eq(res, MY_EXIT_FAILURE);
    cr_assert_eq(head, temp);
}

Test(matching_nodes, test_none_matching_nodes)
{
    node_t *head = NULL;
    node_t *temp = NULL;
    int i = 2;
    int res = 0;
    char *src = "1,3,2";
    char str[3][8] = {"1,1,1","2,2,2","3,3,1"};

    for (; i >= 0; i--)
        head = add_node(str[i], head);
    temp = head;
    res = matching_node(src, head);
    cr_assert_eq(res, 1);
    cr_assert_eq(head, temp);
}

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
    node_t *node = NULL;
    char **str;
    char tab[4][8] = {"1,1,1", "2,2,2", "3,3,1", "4,4,2"};

    for (; i >= 0; i--)
        node = add_node(tab[i], node);
    cr_assert_eq(list_length(node), 4);
    for (; node != NULL; node = node->next) {
        str = my_str_to_word_array(tab[j], ",");
        cr_assert_eq(node->x, atoi(str[0]));
        cr_assert_eq(node->y, atoi(str[1]));
        cr_assert_eq(node->player, atoi(str[2]));
        j++;
    }
    cr_assert_eq(j, 4);
}

Test(store_board, simple_insertion_of_a_node)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "1,1,1";
    int res = 0;

    gom->size = 20;
    res = store_board(str, gom);
    cr_assert_eq(res, 0);
    cr_assert_null(head->next);
    cr_assert_eq(head->x, 1);
    cr_assert_eq(head->y, 1);
    cr_assert_eq(head->player, 1);
}

Test(store_board, insertion_failed_invalid_str)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "1,21,1";
    int res = 0;

    gom->size = 20;
    res = store_board(str, gom);
    cr_assert_eq(res, 84);
    cr_assert_null(head);
    cr_assert_eq(check_string(str, gom), 84);
}

Test(store_board, insertion_failed_matching_nodes)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "1,19,1";
    char *str2 = "1,19,2";
    int res = 0;

    gom->size = 20;
    store_board(str, gom);
    res = store_board(str2, gom);
    cr_assert_eq(res, 84);
    cr_assert_eq(matching_node(str2, head), 84);
}