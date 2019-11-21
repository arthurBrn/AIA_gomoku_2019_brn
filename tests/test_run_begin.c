/*
** EPITECH PROJECT, 2019
** test_run_begin.c
** File description:
** test all functions of file run_begin.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>

// Test game not started
/*Test(run_begin, game_not_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BEGIN";
    int res = 0;

    gom->player = 0;
    gom->start = 0;
    res = run_begin(gom, str);
    cr_assert_eq(res, 1);
}
*/

// Test game started
Test(run_begin, game_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "BEGIN";

    gom->start = 1;
    run_begin(gom, str);
    cr_assert_eq(gom->player, 1);
}
