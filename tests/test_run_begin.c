/*
** EPITECH PROJECT, 2019
** test_run_begin.c
** File description:
** test all functions of file run_begin.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>

Test(run_begin, invalid_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BEGIN ";
    int res = 0;

    gom->player = 0;
    res = run_begin(gom, str);
    cr_assert_eq(res, 2);
}

Test(run_begin, invalid_cmd_two)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "begin";
    int res = 0;

    gom->player = 0;
    res = run_begin(gom, str);
    cr_assert_eq(res, 2);
}

Test(run_begin, invalid_cmd_three)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "START";
    int res = 0;

    gom->player = 0;
    res = run_begin(gom, str);
    cr_assert_eq(res, 2);
}

Test(run_begin, invalid_player_valid_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BEGIN";
    int res = 0;

    gom->player = 1;
    res = run_begin(gom, str);
    cr_assert_eq(res, 2);
}

Test(run_begin, invalid_cmd_invalid_player)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BEGIN ";
    int res = 0;

    gom->player = 3;
    gom->start = 1;
    res = run_begin(gom, str);
    cr_assert_eq(res, 2);
}

Test(run_begin, game_not_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BEGIN";
    int res = 0;

    gom->player = 0;
    gom->start = 0;
    res = run_begin(gom, str);
    cr_assert_eq(res, 1);
}

Test(run_begin, valid_str_player_game_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BEGIN";
    int res = 0;

    gom->player = 0;
    gom->start = 1;
    res = run_begin(gom, str);
    cr_assert_eq(res, 0);
    cr_assert_eq(gom->player, 1);
}
