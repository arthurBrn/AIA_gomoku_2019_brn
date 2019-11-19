/*
** EPITECH PROJECT, 2019
** test_run_end.c
** File description:
** test all function of file src/run_end.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>

Test(test_run, invalid_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "END ";
    int res = 0;

    res = run_end(gom, str);
    cr_assert_eq(res, 2);
}

Test(test_run, invalid_min_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "end";
    int res = 0;

    res = run_end(gom, str);
    cr_assert_eq(res, 2);
}

Test(test_run, wrong_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "start";
    int res = 0;

    res = run_end(gom, str);
    cr_assert_eq(res, 2);
}

Test(test_run, game_not_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "END";
    int res = 0;

    gom->start = 0;
    res = run_end(gom, str);
    cr_assert_eq(res, 1);
}


Test(test_run, game_started_valid_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "END";
    int res = 0;

    gom->start = 1;
    res = run_end(gom, str);
    cr_assert_eq(res, 0);
    cr_assert_eq(gom->end, 1);
}
