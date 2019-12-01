/*
** EPITECH PROJECT, 2019
** test_store_diagonal
** File description:
** Test all functions from file store_diagonal.c
*/

#include "global.h"
#include <criterion/criterion.h>

Test(initialize_block, test_init_block_diag)
{
    int player = 1;
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char str[3][6] = {"3,1,1","2,2,1", "1,3,1"};
    int i = 2;
    int res = 0;

    gom->size = 4;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    res = check_diag_right_to_left(gom, 1, 1);
    cr_assert_eq(aligned_length(), 1);
    cr_assert_eq(aligned->start_x, 3);
    cr_assert_eq(aligned->start_y, 1);
    cr_assert_eq(aligned->len, 3);
    cr_assert_eq(aligned->end_x, 1);
    cr_assert_eq(aligned->end_y, 3);
    cr_assert_eq(aligned->open, 0);
}


Test(set_len_diagonal, test_len_diag)
{
    int player = 1;
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char str[2][6] = {"3,1,1","2,2,1"};
    int i = 1;
    int res = 0;

    gom->size = 10;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    res = check_diag_right_to_left(gom, 1, 1);
    cr_assert_eq(aligned_length(), 1);
    cr_assert_eq(aligned->start_x, 3);
    cr_assert_eq(aligned->start_y, 1);
    cr_assert_eq(aligned->end_x, 2);
    cr_assert_eq(aligned->end_y, 2);
    cr_assert_eq(aligned->len, 2);
    cr_assert_eq(aligned->open, 2);
}

Test(set_len_diagonal, test_len_diag_w_other_player_stones)
{
    int player = 1;
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char str[4][6] = {"5,1,1","4,2,2","3,3,2","2,4,2"};
    int i = 3;
    int res = 0;

    gom->size = 6;
    for (i; i >= 0; i--)
        store_board(str[i], gom);
    cr_assert_eq(list_length(head), 4);
    res = check_diag_right_to_left(gom, 1, 1);
    //res = check_diag_left_to_right(gom, 1, 1);
    cr_assert_eq(aligned_length(), 2);
    cr_assert_not_null(aligned->next);
    cr_assert_eq(aligned_length(), 2);
    aligned = aligned->next;
    cr_assert_eq(aligned->start_x, 5);
    cr_assert_eq(aligned->start_y, 2);
    cr_assert_eq(aligned->end_x, 2);
    cr_assert_eq(aligned->end_y, 4);
    cr_assert_eq(aligned->len, 3);
    cr_assert_eq(aligned->open, 2);
}