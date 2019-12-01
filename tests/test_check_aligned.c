/*
** EPITECH PROJECT, 2019
** test_check_aligned.c
** File description:
** test function of file check aligned.c
*/

#include <criterion/criterion.h>
#include "global.h"

Test(count_horizontal, finding_x_y_in_linked_list_of_one)
{
    int res = 0;
    int x = 1;
    int y = 1;
    node_t *node_head = malloc(sizeof(node_t));
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    
    gom->size = 20;
    gom->start = 1;
    al->player = 1;
    aligned = al;
    node_head = add_node("1,1,1", node_head);
    res = count_horizontal(gom, x, y, node_head);
    cr_assert_eq(res, 1);
    cr_assert_not_null(node_head);
}

Test(count_horizontal, not_finding_x_y_in_linked_list_of_one)
{
    int res = 0;
    int x = 2;
    int y = 1;
    node_t *node_head = malloc(sizeof(node_t));
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    
    gom->size = 20;
    gom->start = 1;
    al->player = 1;
    aligned = al;
    node_head = add_node("1,1,1", node_head);
    res = count_horizontal(gom, x, y, node_head);
    cr_assert_eq(res, 0);
    cr_assert_not_null(node_head);
}

Test(count_horizontal, not_finding_x_y_in_linked_list_of_x_nodes)
{
    int res = 0;
    int i = 3;
    int x = 1;
    int y = 1;
    char str[4][6] = {"1,1,2","1,2,1","1,3,1","1,4,2"};
    node_t *node_head = malloc(sizeof(node_t));
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    
    gom->size = 20;
    gom->start = 1;
    al->player = 1;
    aligned = al;
    for (i; i >= 0; i--)
        node_head = add_node(str[i], node_head);
    res = count_horizontal(gom, x, y, node_head);
    cr_assert_eq(res, 0);
    cr_assert_not_null(node_head);
}

Test(count_horizontal, finding_x_y_in_linked_list_of_x_nodes)
{
    int res = 0;
    int i = 3;
    int x = 1;
    int y = 1;
    char str[4][6] = {"1,1,2","1,2,1","1,3,1","1,4,2"};
    node_t *node_head = malloc(sizeof(node_t));
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    
    gom->size = 20;
    gom->start = 1;
    al->player = 2;
    aligned = al;
    for (i; i >= 0; i--)
        node_head = add_node(str[i], node_head);
    res = count_horizontal(gom, x, y, node_head);
    cr_assert_eq(res, 1);
    cr_assert_not_null(node_head);
}

Test(count_horizontal, not_finding_x_y_in_linked_list_null)
{
    int res = 0;
    int x = 1;
    int y = 1;
    node_t *node_head = NULL;
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    
    res = count_horizontal(gom, x, y, node_head);
    cr_assert_eq(res, 0);
    cr_assert_null(node_head);
}

Test(find_one, find_row_of_stone_from_other_player)
{
    int x = 1;
    int y = 1;
    int i = 3;
    int res = 0;
    char str[4][6] = {"1,1,2","2,1,2","3,1,2","4,1,2"};
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    node_t *node = malloc(sizeof(node_t));

    al->player = 1;
    aligned = al;
    gom->size = 20;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 4);
    res = find_one(gom, x, y, head);
    cr_assert_eq(res, 0);
}   

Test(find_one, find_row_of_stone_from_our_player)
{
    int x = 1;
    int y = 1;
    int i = 3;
    int res = 0;
    char str[4][6] = {"1,1,2","2,1,2","3,1,2","4,1,2"};
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    node_t *node = malloc(sizeof(node_t));

    al->player = 2;
    aligned = al;
    gom->size = 20;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 4);
    res = find_one(gom, x, y, head);
    cr_assert_eq(res, 4);
}   

Test(find_one, fin_several_stone_on_several_row_from_our_player)
{
    int x = 1;
    int y = 1;
    int i = 3;
    int res = 0;
    char str[4][6] = {"1,1,2","2,2,2","3,3,2","4,4,2"};
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    node_t *node = malloc(sizeof(node_t));

    al->player = 2;
    aligned = al;
    gom->size = 20;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 4);
    res = find_one(gom, x, y, head);
    cr_assert_eq(res, 1);
}   

Test(find_one, fin_several_stone_on_several_row_from_other_player)
{
    int x = 1;
    int y = 1;
    int i = 3;
    int res = 0;
    char str[4][6] = {"1,1,2","2,2,2","3,3,2","4,4,2"};
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    node_t *node = malloc(sizeof(node_t));

    al->player = 1;
    aligned = al;
    gom->size = 20;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 4);
    res = find_one(gom, x, y, head);
    cr_assert_eq(res, 0);
}   

Test(check_horizontal, playing_two_combinaison)
{
    aligned_t *al = malloc(sizeof(aligned_t));
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int i = 4;
    int res = 0;
    char str[5][6] = {"1,1,1","2,1,1","3,1,1","4,1,1", "4,3,2"};

    gom->size = 10;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 5);
    res = check_horizontal(gom, 1, 1);
    cr_assert_eq(res, 0);
    cr_assert_eq(aligned_length(), 2);
    cr_assert_eq(aligned->start_x, 4);
    cr_assert_eq(aligned->start_y, 3);
    cr_assert_eq(aligned->end_x, 4);
    cr_assert_eq(aligned->end_y, 3);
    cr_assert_eq(aligned->len, 1);
    cr_assert_eq(aligned->player, 2);
    cr_assert_not_null(aligned->next);
    al = aligned->next;
    cr_assert_eq(al->start_x, 1);
    cr_assert_eq(al->start_y, 1);
    cr_assert_eq(al->end_x, 4);
    cr_assert_eq(al->end_y, 1);
    cr_assert_eq(al->len, 4);
    cr_assert_eq(al->player, 1);
    cr_assert_null(al->next);
    cr_assert_not_null(aligned);
    aligned_list_free();
    cr_assert_null(aligned);
}

Test(check_aligned, verify_free_after_check_aligned)
{
    int i = 3;
    char str[4][6] = {"1,1,1","2,1,1","3,1,2","4,1,2"};
    t_gomoku *gom = malloc(sizeof(t_gomoku));

    gom->size=5;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_null(aligned);
    check_aligned(gom);
    cr_assert_null(aligned);
}

Test(check_aligned, verify_proper_insertion_check_aligned)
{
    int i = 3;
    int player = 1;
    char str[4][6] = {"1,1,1","2,1,1","3,1,1","4,1,1"};
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = malloc(sizeof(aligned_t));
    node_t *node = NULL;

    gom->size=5;
    gom->start = 1;
    al = aligned;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    node = head;
    check_horizontal(gom, 1,1);
    cr_assert_eq(node, head);
    cr_assert_not_null(aligned);
    check_aligned(gom);
    while (al != NULL) {
        cr_assert_eq(al->player, player);
        cr_assert_eq(al->end_x, 4);
        cr_assert_eq(al->end_y, 1);
        cr_assert_eq(al->start_x, 1);
        cr_assert_eq(al->start_y, 1);
        cr_assert_eq(al->len, 4);
        al = al->next;
    }
    cr_assert_eq(node, head);
    cr_assert_null(aligned);
}
