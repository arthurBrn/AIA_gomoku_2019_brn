/*
** EPITECH PROJECT, 2019
** test_run_begin.c
** File description:
** test all functions of file run_begin.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_stdout_run_begin(void)
{
    cr_redirect_stdout();
}

Test(run_begin, game_not_started, .init=redirect_stdout_run_begin)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BEGIN";
    int res = 0;

    gom->start = 0;
    run_begin(gom, str);
    cr_assert_stdout_eq_str(GAME_NOT_STARTED);
}

Test(run_begin, game_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BEGIN";

    gom->start = 1;
    run_begin(gom, str);
    cr_assert_eq(gom->player, 1);
}
