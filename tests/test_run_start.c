/*
** EPITECH PROJECT, 2019
** test_run_start.c
** File description:
** test all function in src/run_start.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>

Test(run_start, invalid_min_cmd)
{
    char *str = "start 20";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    res = run_start(gom, str);
    cr_assert_eq(res, 2);
}

Test(run_start, invalid_cmd)
{
    char *str = "STAR 20";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    res = run_start(gom, str);
    cr_assert_eq(res, 2);
}

Test(run_start, valid_cmd_w_invalid_param)
{
    char *str = "START 0";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    res = run_start(gom, str);
    cr_assert_eq(res, 84);
}

Test(run_start, valid_cmd_w_no_param)
{
    char *str = "START";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    res = run_start(gom, str);
    cr_assert_eq(res, 84);
}

Test(run_start, valid_cmd_w_too_big_param)
{
    char *str = "START 25";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    res = run_start(gom, str);
    cr_assert_eq(res, 84);
}

Test(run_start, valid_cmd_valid_size_and_game_not_started)
{
    char *str = "START 20";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->start = 0;
    res = run_start(gom, str);
    cr_assert_eq(res, 0);
    cr_assert_eq(gom->size, 20);
    cr_assert_eq(gom->start, 1);
}

Test(run_start, valid_cmd_valid_size_game_already_started)
{
    char *str = "START 20";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->start = 1;
    res = run_start(gom, str);
    cr_assert_eq(res, 1);
    cr_assert_eq(gom->start, 1);
}

Test(run_start, valid_cmd_invalid_size_game_not_started)
{
    char *str = "START 26";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->start = 0;
    res = run_start(gom, str);
    cr_assert_eq(res, 1);
}
