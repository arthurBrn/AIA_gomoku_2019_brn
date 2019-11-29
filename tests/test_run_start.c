/*
** EPITECH PROJECT, 2019
** test_run_start.c
** File description:
** test all function of file run_start.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(run_start, game_already_started)
{
    char *str = "";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->start = 1;
    res = run_start(gom, str);
    cr_assert_eq(res, ERROR);
}

Test(run_start, game_not_started_valid_str_but_size_zero)
{
    char *str = "0";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->start = 0;
    res = run_start(gom, str);
    cr_assert_eq(res, 84);
}


Test(run_start, str_invalid_game_not_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "2a0";
    int res = 0;

    gom->start = 0;
    res = run_start(gom, str);
    cr_assert_eq(res, 84);
}

Test(run_start, str_invalid_game_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "2a0";
    int res = 0;

    gom->start = 1;
    res = run_start(gom, str);
    cr_assert_eq(res, 84);
}


Test(run_start, str_valid_game_not_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "20";
    int res = 0;

    gom->start = 0;
    res = run_start(gom, str);
    cr_assert_eq(res, 0);
    cr_assert_eq(gom->size, 20);
    cr_assert_eq(gom->start, 1);
}
