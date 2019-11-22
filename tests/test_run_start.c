/*
** EPITECH PROJECT, 2019
** test_run_start.c
** File description:
** test all function of file run_start.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_stdout_run_start(void)
{
    cr_redirect_stderr();
}

Test(run_start, game_already_started)
{
    char *str = "20";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->start = 1;
    res = run_start(gom, str);
    cr_assert_not_null(res);
}


Test(run_start, game_not_started_str_invalid, .init=cr_redirect_stderr)
{
    char *str = "0";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->start = 0;
    run_start(gom, str);
    cr_assert_stderr_eq_str(ERROR_MSG);
}













// Test size of zero
/*Test(run_start, str_size_of_zero)
{
    char *str = "0";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->start = 0;
    res = run_start(gom, str);
    cr_assert_eq(res, 84);
    cr_assert_eq(gom->start, 0);
    cr_assert_eq(gom->size, 0);
}
*/

// Test invalid size => 2a0
/*
Test(run_start, str_invalid_size)
{
    char *str = "2a0";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->start = 0;
    res = run_start(gom, str);
    cr_assert_eq(gom->start, 1);
}
*/

