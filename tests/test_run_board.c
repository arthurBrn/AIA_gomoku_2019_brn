/*
** EPITECH PROJECT, 2019
** test_run_board.c
** File description:
** test all function of file run_board.c
*/

#include "global.h"
#include <criterion/criterion.h>

Test(run_board, game_not_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BOARD";
    int res = 0;

    gom->start = 0;
    res = run_board(gom,str);
    cr_assert_eq(res, MY_EXIT_FAILURE);
}

Test(run_board, str_param_must_be_null)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BOARD";
    int res = 0;

    gom->start = 1;
    res = run_board(gom,str);
    cr_assert_eq(res, MY_EXIT_FAILURE);
}
