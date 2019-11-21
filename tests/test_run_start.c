/*
** EPITECH PROJECT, 2019
** test_run_start.c
** File description:
** test all function in src/run_start.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>

Test(run_start, game_already_started)
{
    char *str = "20";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->start = 1;
    res = run_start(gom, str);
    cr_assert_neq(res, 0);
}

Test(run_start, game_not_started_valid_size)
{
    char *str = "5";
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    int res = 0;

    gom->start = 0;
    res = run_start(gom, str);
    cr_assert_eq(gom->size, 5);
    cr_assert_eq(gom->start, 1);
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

