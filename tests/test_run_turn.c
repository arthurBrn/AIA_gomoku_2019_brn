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
    char *str = "11,";
    int res = 0;

    res = check_error(gom, str);
    cr_assert_eq(res, 84);
}

Test(check_error, str_starting_by_coma)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = ",11";
    int res = 0;

    res = check_error(gom, str);
    cr_assert_eq(res, 84);
}

Test(check_error, str_too_much_coma)
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

Test(check_error, coordonate_x_y_larger_than_board)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "21,21";
    int res = 0;

    gom->size = 20;
    res = check_error(gom, str);
    cr_assert_eq(res, 84);
}

Test(check_error, coordonate_x_larger_than_board)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "21,19";
    int res = 0;

    gom->size = 20;
    res = check_error(gom, str);
    cr_assert_eq(res, 84);
}

Test(check_error, coordonate_y_larger_than_board)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "19,21";
    int res = 0;

    gom->size = 20;
    res = check_error(gom, str);
    cr_assert_eq(res, 84);
}

Test(check_error, coordonate_x_or_y_equal_to_zero)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "0,19";
    char *str2 = "19,0";
    int res = 0;

    gom->size = 20;
    res = check_error(gom, str);
    cr_assert_eq(res, 84);
    res = check_error(gom, str2);
    cr_assert_eq(res, 84);
}

Test(check_error, coordonate_equal_to_board)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "20,20";
    int res = 0;

    gom->size = 20;
    res = check_error(gom, str);
    cr_assert_eq(res, 0);
}

Test(check_error, str_w_invalid_chars)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "5a,5";
    int res = 0;

    gom->size = 20;
    res = check_error(gom, str);
    cr_assert_eq(res, 84);
}

Test(init_begin, no_player)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));

    init_begin(gom);
    cr_assert_eq(gom->player, 2);
}

Test(init_begin, player_one_defined)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));

    gom->player = 1;
    init_begin(gom);
    cr_assert_eq(gom->player, 1);
}

Test(init_begin, player_two_defined)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));

    gom->player = 2;
    init_begin(gom);
    cr_assert_eq(gom->player, 2);
}

// Game not started
/*
Test(run_turn, game_not_started)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "TURN 10,10";
    int res = 0;

    gom->start = 0;
    res = run_turn(gom, str);
    cr_assert_eq(res, 0);
}
*/

// Game started but coordonate error
/*Test(run_turn, game_started_check_error_pos)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "10,,10";
    int res = 0;

    gom->start = 1;
    gom->size = 11;
    res = run_turn(gom, str);
    cr_assert_eq(res, 1);
}*/

// Game started but coordonate out of grid
 /*Test(run_turn, game_started_coordonate_out_of_grid)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "10,10";
    int res = 0;

    gom->start = 1;
    gom->size = 9;
    res = run_turn(gom, str);
    cr_assert_eq(res, 1);
}
*/

//
Test(run_turn, game_started_check_error_neg)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "10,10";
    int res = 0;

    gom->size = 11;
    gom->start = 1;
    res = run_turn(gom, str);
    cr_assert_eq(res, 0);
    cr_assert_eq(gom->start, 1);
    cr_assert_eq(gom->player, 2);
}
