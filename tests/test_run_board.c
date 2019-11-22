/*
** EPITECH PROJECT, 2019
** test_run_board.c
** File description:
** test all function of file run_board.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(run_board, game_not_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BOARD";
    int res = 0;

    gom->start = 0;
    res = run_board(gom,str);
    cr_assert_not_null(res);
}

