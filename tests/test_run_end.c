/*
** EPITECH PROJECT, 2019
** test_run_end.c
** File description:
** test all function of file src/run_end.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>

Test(test_run, game_not_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "END";
    int temp_end = gom->end;
    int temp_start = gom->start;

    gom->start = 0;
    run_end(gom, str);
    cr_assert_eq(gom->end, temp_end);
    cr_assert_eq(gom->start, temp_start);
}

Test(test_run, game_started_valid_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "END";

    gom->start = 1;
    run_end(gom, str);
    cr_assert_eq(gom->end, 1);
    cr_assert_eq(gom->start, 1);
}
