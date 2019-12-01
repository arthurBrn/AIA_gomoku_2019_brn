/*
** EPITECH PROJECT, 2019
** test_make_move.c
** File description:
** test all function from file make_move.c
*/

#include "global.h"
#include <criterion/criterion.h>

Test(find_best_move, test_return_biggest_value)
{
    int i = 3;
    char str[4][6] = {"1,1,1", "2,1,1", "3,1,1", "3,2,1"};
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = NULL;
    aligned_t *res = NULL;

    gom->size = 5;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    check_horizontal(gom, 1, 1);
    cr_assert_eq(aligned->start_x, 3);
    al = aligned->next;
    res = find_best_move();
    cr_assert_eq(res, al);
}

Test(find_best_move, test_return_if_its_same_value)
{
    int i = 2;
    char str[4][6] = {"1,1,1", "3,2,1"};
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    aligned_t *al = NULL;
    aligned_t *res = NULL;

    gom->size = 5;
    gom->start = 1;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    check_horizontal(gom, 1, 1);
    al = aligned->next;
    res = find_best_move();
    cr_assert_eq(res, aligned);
}