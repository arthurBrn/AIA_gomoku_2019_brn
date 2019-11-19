/*
** EPITECH PROJECT, 2019
** test_run_turn.c
** File description:
** test all function of file src/run_turn.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>

Test(check_error, str_ending_by_coma)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "1,1,";
    int res = 0;

    res = check_error(gom, str);
    cr_assert_eq(res, 84);
}

Test(check_error, str_starting_by_coma)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = ",1,1";
    int res = 0;

    res = check_error(gom, str);
    cr_assert_eq(res, 84);
}

Test(check_error, str_valid)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "10,10";
    int res = 0;

    gom->size = 20;
    res = check_error(gom, str);
    cr_assert_eq(res, 0);
}

Test(check_error, coordonate_larger_than_board)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "21,21";
    char *str2 = "20,21";
    char *str3 = "21,20";
    int res = 0;

    gom->size = 20;
    res = check_error(gom, str);
    cr_assert_eq(res, 84);
    res = check_error(gom, str2);
    cr_assert_eq(res, 84);
    res = check_error(gom, str3);
    cr_assert_eq(res, 84);
}

Test(run_turn, invalid_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "TURN     ";
    int res = 0;

    res = run_turn(gom, str);
    cr_assert_eq(res, 2);
}

Test(run_turn, invalid_min_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "turn";
    int res = 0;

    res = run_turn(gom, str);
    cr_assert_eq(res, 2);
}

Test(run_turn, invalid_wrong_cmd)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "START";
    int res = 0;

    res = run_turn(gom, str);
    cr_assert_eq(res, 2);
}

Test(run_turn, valid_cmd_game_not_start)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "TURN";
    int res = 0;
    gom->start = 0;

    res = run_turn(gom, str);
    cr_assert_eq(res, 0);
}

