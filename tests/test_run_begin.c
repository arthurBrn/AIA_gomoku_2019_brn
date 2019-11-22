/*
** EPITECH PROJECT, 2019
** test_run_begin.c
** File description:
** test all functions of file run_begin.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

/*
void redirect_stderr_run_begin(void)
{
    cr_redirect_stderr();
}

Test(run_begin, game_not_started, .init=cr_redirect_stderr)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "";
    int res = 0;

    gom->start = 0;
    res = run_begin(gom, str);
    cr_assert_eq(res, 0);
    cr_assert_stderr_eq_str(GAME_NOT_STARTED);
}
*/
Test(run_begin, game_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "";

    gom->start = 1;
    run_begin(gom, str);
    cr_assert_eq(gom->player, 1);
}
