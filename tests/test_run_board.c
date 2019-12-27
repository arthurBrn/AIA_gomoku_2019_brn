/*
** EPITECH PROJECT, 2019
** test_run_board.c
** File description:
** test all function of file run_board.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>

Test(list_length, find_length_four)
{
    t_board *node = NULL;
    char coord[4][8] = {"1,1,2","2,2,1","3,3,2","4,4,1"};
    int i = 3;

    node = init_board();
    for (; i >= 0; i--)
        node = store_move(node, coord[i], ",");
    cr_assert_eq(list_length(node), 4);
}

Test(list_length, list_no_length)
{
    t_board *node = NULL;

    cr_assert_eq(list_length(node), 0);
}

Test(list_length, not_losing_the_head)
{
    t_board *node = NULL;
    t_board *keep_the_head = NULL;
    char coord[4][8] = {"1,1,2","2,2,1","3,3,2","4,4,1"};
    int i = 3;

    node = init_board();    
    for (; i >= 0; i--)
        node = store_move(node, coord[i], ",");
    keep_the_head = node;
    cr_assert_eq(list_length(node), 4);
    cr_assert_eq(keep_the_head, node);
}

Test(print_list, keeping_the_head)
{
    t_board *node = NULL;
    t_board *keep_the_head = NULL;
    char coord[4][8] = {"1,1,2","2,2,1","3,3,2","4,4,1"};
    int i = 3;

    node = init_board();    
    for (; i >= 0; i--)
        node = store_move(node, coord[i], ",");
    keep_the_head = node;
    print_list(node);
    cr_assert_eq(keep_the_head, node);
}

Test(error_board, game_not_started_board_not_initialized)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *s1 = "";

    gom->start = 0;
    gom->board = NULL;
    cr_assert_eq(error_board(gom, s1), MY_EXIT_FAILURE);
}

Test(error_board, game_started_board_not_initialized)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *s1 = "";

    gom->board = NULL;
    gom->start = 1;
    cr_assert_eq(error_board(gom, s1), MY_EXIT_FAILURE);
}

Test(error_board, game_not_started_board_initialized)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *s1 = "";

    gom->board = init_board();
    gom->start = 0;
    cr_assert_eq(error_board(gom, s1), MY_EXIT_FAILURE);
}

Test(error_board, game_started_board_initialized_invalid_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *s1 = "error";

    gom->board = init_board();
    gom->start = 1;
    cr_assert_eq(error_board(gom, s1), MY_EXIT_FAILURE);
}

Test(error_board, game_started_board_initialized_valid_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *s1 = "";

    gom->board = init_board();
    gom->start = 1;
    cr_assert_eq(error_board(gom, s1), 0);
}

Test(storing_error, check_string_working_properly)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *delim = ",";
    char *s1 = "1,,1,1";
    char *s2 = "1,?,a";
    char *s3 = "1,24,1";
    char *s4 = "1,1,5";

    gom->size = 20;
    gom->start = 1;
    cr_assert_eq(storing_error(s1, gom, delim), MY_EXIT_FAILURE);
    cr_assert_eq(storing_error(s2, gom, delim), MY_EXIT_FAILURE);
    cr_assert_eq(storing_error(s3, gom, delim), MY_EXIT_FAILURE);
    cr_assert_eq(storing_error(s4, gom, delim), MY_EXIT_FAILURE);
}

Test(storing_error, correct_format_data_already_stored)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    gom->board = init_board();
    char *delim = ",";
    char *s1 = "1,1,1";
    char *s2 = "1,1,2";

    gom->size = 20;
    gom->start = 1;
    gom->board->x = 1;
    gom->board->y = 1;
    gom->board->player = 1;
    cr_assert_eq(storing_error(s1, gom, delim), MY_EXIT_FAILURE);
    cr_assert_eq(storing_error(s2, gom, delim), MY_EXIT_FAILURE);
}

Test(storing_error, correct_format_data_not_stored_at_first)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    gom->board = init_board();
    char *delim = ",";
    char *s1 = "1,1,1";
    char *s2 = "1,1,2";

    gom->size = 20;
    gom->start = 1;
    cr_assert_eq(storing_error(s1, gom, delim), 0);
    gom->board->x = 1;
    gom->board->y = 1;
    gom->board->player = 1;
    cr_assert_eq(storing_error(s2, gom, delim), MY_EXIT_FAILURE);
}

Test(init_board, normal_init)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));

    gom->board = init_board();
    cr_assert_eq(gom->board->x, -1);
    cr_assert_eq(gom->board->y, -1);
    cr_assert_eq(gom->board->player, -1);
    cr_assert_null(gom->board->next);
}

Test(set_node, assign_correct_values)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *coordonate = "1,1,1";
    char *delim = ",";
    char **split = my_str_to_word_array(coordonate, delim);

    gom->size = 20;
    gom->start = 1;
    gom->board = init_board();
    set_node(gom->board, coordonate, delim);
    cr_assert_eq(gom->board->x, atoi(split[0]));
    cr_assert_eq(gom->board->y, atoi(split[1]));
    cr_assert_eq(gom->board->player, atoi(split[2]));
    cr_assert_null(gom->board->next);
}

Test(store_move, add_one_node)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *coordonate = "1,1,1";

    gom->board = init_board();
    store_move(gom->board, coordonate, ",");
    cr_assert_eq(gom->board->x, 1);
    cr_assert_eq(gom->board->y, 1);
    cr_assert_eq(gom->board->player, 1);
    cr_assert_null(gom->board->next);
}

Test(store_move, add_several_node)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    t_board *board = malloc(sizeof(t_board));
    char coord[4][8] = {"1,1,1", "2,2,1", "3,3,1", "4,4,1"};
    char **str;
    int i = 3;
    int j = 0;

    gom->board = init_board();
    for (; i >= 0; i--)
        gom->board = store_move(gom->board, coord[i], ",");
    cr_assert_eq(list_length(gom->board), 4);
    board = gom->board;
    for (;board != NULL; board = board->next) {
        str = my_str_to_word_array(coord[j], ",");
        cr_assert_eq(board->x, atoi(str[0]));
        cr_assert_eq(board->y, atoi(str[1]));
        cr_assert_eq(board->player, 1);
        j++;
    }
}

Test(run_board, game_not_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BOARD";

    gom->start = 0;
    cr_assert_eq(run_board(gom, str), MY_EXIT_FAILURE);
}