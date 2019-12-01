/*
** EPITECH PROJECT, 2019
** test_check_vertical.c
** File description:
** Test all function from file check_vertical
*/

#include "global.h"
#include <criterion/criterion.h>


Test(count_vertical, list_size_one_finding_mathing_coordonate)
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
    res = count_vertical(gom, x, y, node_head);
    cr_assert_eq(res, 1);
    cr_assert_not_null(node_head);
}


Test(count_vertical, list_size_one_not_finding_matching_coordonate)
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
    res = count_vertical(gom, x, y, node_head);
    cr_assert_eq(res, 0);
    cr_assert_not_null(node_head);
}

Test(count_vertical, list_size_x_non_matching_coordonate)
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
    res = count_vertical(gom, x, y, node_head);
    cr_assert_eq(res, 0);
    cr_assert_not_null(node_head);
}

Test(count_vertical, list_x_nodes_matching_coordonate)
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
    res = count_vertical(gom, x, y, node_head);
    cr_assert_eq(res, 1);
    cr_assert_not_null(node_head);
}

Test(count_horizontal, list_null_not_matching)
{
    int res = 0;
    int x = 1;
    int y = 1;
    node_t *node_head = NULL;
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    
    res = count_vertical(gom, x, y, node_head);
    cr_assert_eq(res, 0);
    cr_assert_null(node_head);
}

Test(find_one_vertical, find_vertical_row_of_stone_from_other_player)
{
    int x = 1;
    int y = 1;
    int i = 3;
    int res = 0;
    char str[4][6] = {"1,1,2","1,2,2","1,3,2","1,4,2"};
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
    res = find_one_vertical(gom, x, y, head);
    cr_assert_eq(res, 0);
}   

Test(find_one_vertical, find_vertical_row_of_stone_from_our_player)
{
    int x = 1;
    int y = 1;
    int i = 3;
    int res = 0;
    char str[4][6] = {"1,1,2","1,2,2","1,3,2","1,4,2"};
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
    res = find_one_vertical(gom, x, y, head);
    cr_assert_eq(res, 4);
}   

Test(find_one_vertical, fin_several_stone_on_several_col_from_our_player)
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
    res = find_one_vertical(gom, x, y, head);
    cr_assert_eq(res, 1);
}   

Test(find_one_vetrical, fin_several_stone_vertical_on_several_col_from_other_player)
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
    res = find_one_vertical(gom, x, y, head);
    cr_assert_eq(res, 0);
}   

Test(check_vertical, test_proper_insertion_in_list_vertical_only)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    //char str[4][6] = {"1,2,1", "1,3,1", "2,4,1", "1,5,1"};
    char str[4][6] = {"1,2,1", "1,3,1"};
    int res = 0;
    int i = 3;

    gom->size = 20;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 2);
    res = check_vertical(gom, 1, 1);
    cr_assert_eq(res, 0);
    cr_assert_not_null(aligned);
    cr_assert_eq(aligned_length(), 1);
    cr_assert_eq(aligned->start_x, 1);
    cr_assert_eq(aligned->start_y, 2);
    cr_assert_eq(aligned->end_x, 1);
    cr_assert_eq(aligned->end_y, 3);
    cr_assert_eq(aligned->len, 2);
    cr_assert_eq(aligned->player, 1);
}

Test(check_vertical, test_proper_fusion_of_two_sets_of_stones)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char str[4][6] = {"1,1,1", "1,2,1", "1,4,1", "1,5,1"};
    int res = 0;
    int i = 3;

    gom->size = 20;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 4);
    res = check_vertical(gom, 1,1);
    cr_assert_eq(res, 0);
    cr_assert_eq(aligned_length(), 2);
    cr_assert_eq(aligned->start_x, 1);
    cr_assert_eq(aligned->start_y, 4);
    cr_assert_eq(aligned->end_x, 1);
    cr_assert_eq(aligned->end_y, 5);
    cr_assert_eq(aligned->len, 2);
    cr_assert_not_null(aligned->next);
    cr_assert_eq(aligned->next->start_x, 1);
    cr_assert_eq(aligned->next->start_y, 1);
    cr_assert_eq(aligned->next->end_x, 1);
    cr_assert_eq(aligned->next->end_y, 2);
    cr_assert_eq(aligned->next->len, 2);
    cr_assert_null(aligned->next->next);
    aligned_list_free();
    store_board("1,3,1", gom);
    res = check_vertical(gom,1,1);
    cr_assert_eq(res, 0);
    cr_assert_eq(aligned_length(), 1);
}


Test(check_vertical, test_proper_insertion_in_list_vertical_and_horizontal)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char str[6][6] = {"1,1,1","2,1,1","3,1,1", "1,3,1","1,4,1","1,5,1"};
    int res = 0;
    int i = 5;

    gom->size = 20;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 6);
    res = check_horizontal(gom, 1 ,1);
    cr_assert_eq(res, 0);
    cr_assert_eq(aligned_length(), 4);
    aligned_list_free();
    res = check_vertical(gom, 1,1);
    cr_assert_eq(res, 0);
    cr_assert_eq(aligned_length(), 4);
    aligned_list_free();
    check_horizontal(gom, 1,1);
    check_vertical(gom, 1,1);
    cr_assert_eq(aligned_length(), 8); 
}


Test(check_vertical, test_proper_insertion_in_list_vertical_and_horizontal_w_same_start_x)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char str[6][6] = {"1,1,1","2,1,1","3,1,1", "1,2,1","1,3,1","1,4,1"};
    int i = 5;

    gom->size = 20;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 6);
    check_vertical(gom, 1,1);
    cr_assert_eq(aligned_length(), 3);
    aligned_list_free();
    check_horizontal(gom, 1, 1);
    cr_assert_eq(aligned_length(), 4);
    aligned_list_free();    
    check_horizontal(gom, 1, 1);
    check_vertical(gom, 1, 1);
    cr_assert_eq(aligned_length(),7);
    cr_assert_not_null(aligned);
    aligned_list_free();
    cr_assert_null(aligned);
}