/*
** EPITECH PROJECT, 2019
** test_run_board.c
** File description:
** test all function of file run_board.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>

Test(swap, test_swap_working)
{
    t_board *node_one = init_board();

    node_one = store_move(node_one, "1,1,1", ",");
    node_one = store_move(node_one, "2,2,2", ",");

    swap(node_one);
    cr_assert_eq(node_one->x, 1);
    cr_assert_eq(node_one->y, 1);
    cr_assert_eq(node_one->player, 1);
    node_one = node_one->next;
    cr_assert_eq(node_one->x, 2);
    cr_assert_eq(node_one->y, 2);
    cr_assert_eq(node_one->player, 2);
}

Test(sort_board, sort_board_working)
{
    t_board *board = init_board();

    board = store_move(board, "1,2,2", ",");
    board = store_move(board, "2,1,1", ",");
    board = store_move(board, "4,4,2", ",");
    board = store_move(board, "3,2,2", ",");
    board = store_move(board, "1,3,2", ",");
    board = store_move(board, "5,3,2", ",");

    cr_assert_eq(list_length(board), 6);
    sort_board(board);
    cr_assert_eq(list_length(board), 6);
    cr_assert_eq(board->x, 1);
    cr_assert_eq(board->y, 2);  
    board = board->next;
    cr_assert_eq(board->x, 1);
    cr_assert_eq(board->y, 3);
    board = board->next;
    cr_assert_eq(board->x, 2);
    cr_assert_eq(board->y, 1);
    board = board->next;
    cr_assert_eq(board->x, 3);
    cr_assert_eq(board->y, 2);
    board = board->next;
    cr_assert_eq(board->x, 4);
    cr_assert_eq(board->y, 4);
    board = board->next;
    cr_assert_eq(board->x, 5);
    cr_assert_eq(board->y, 3);
    cr_assert_null(board->next);
}

Test(sort_board, sort_two_nodes_same_x_diff_y)
{
    t_board *board = init_board();

    board = store_move(board, "1,2,2", ",");
    board = store_move(board, "1,3,2", ",");

    cr_assert_eq(list_length(board), 2);
    sort_board(board);
    cr_assert_eq(list_length(board), 2);
    cr_assert_eq(board->x, 1);
    cr_assert_eq(board->y, 2);  
    board = board->next;
    cr_assert_eq(board->x, 1);
    cr_assert_eq(board->y, 3);
    cr_assert_null(board->next);
}

Test(sort_board, sort_two_nodes_diff_x_same_y)
{
    t_board *board = init_board();

    board = store_move(board, "1,2,2", ",");
    board = store_move(board, "2,2,2", ",");

    cr_assert_eq(list_length(board), 2);
    sort_board(board);
    cr_assert_eq(list_length(board), 2);
    cr_assert_eq(board->x, 1);
    cr_assert_eq(board->y, 2);  
    board = board->next;
    cr_assert_eq(board->x, 2);
    cr_assert_eq(board->y, 2);
    cr_assert_null(board->next);
}