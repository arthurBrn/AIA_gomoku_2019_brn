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