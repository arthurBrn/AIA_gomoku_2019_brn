/*
** EPITECH PROJECT, 2019
** test_run_turn.c
** File description:
** test all function of file src/run_turn.c
*/

#include "gomoku.h"
#include <criterion/criterion.h>

Test(only_numbers, str_w_invalid_chars)
{
    char *str = "5a,5";
    int res = only_numbers(str);
    cr_assert_eq(res, 84);
}

Test(only_numbers, str_w_valid_chars)
{
    char *str = "10,10";
    int res = only_numbers(str);
    cr_assert_eq(res, 0);
}

Test(count_comma, str_too_much_coma)
{
    char *str = ",1,1";
    int res = count_comma(str);

    cr_assert_eq(res, 84);
}

Test(count_comma, valid_number_and_place_of_coma)
{
    char *str = "1,1";
    int res = count_comma(str);

    cr_assert_eq(res, 0);
}

Test(len_str, valid_str_input)
{
    char *str = "21,21";
    int res = len_str(str);

    cr_assert_eq(res, 0);
}

Test(len_str, invalid_str_input)
{
    char *str = "0,0";
    int res = len_str(str);

    cr_assert_eq(res, 84);
}

Test(xy_invalid, coordonate_x_y_larger_than_board)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "21,21";
    int res = 0;

    gom->size = 20;
    res = xy_invalid(gom, str);
    cr_assert_eq(res, 84);
}

Test(xy_invalid, coordonate_x_larger_than_board)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "21,19";
    int res = 0;

    gom->size = 20;
    res = xy_invalid(gom, str);
    cr_assert_eq(res, 84);
}

Test(xy_invalid, coordonate_y_larger_than_board)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "19,21";
    int res = 0;

    gom->size = 20;
    res = xy_invalid(gom, str);
    cr_assert_eq(res, 84);
}

Test(xy_invalid, coordonate_x_or_y_equal_to_zero)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "0,19";
    char *str2 = "19,0";
    int res = 0;

    gom->size = 20;
    res = xy_invalid(gom, str);
    cr_assert_eq(res, 84);
    res = xy_invalid(gom, str2);
    cr_assert_eq(res, 84);
}

Test(xy_invalid, coordonate_equal_to_board)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "20,20";
    int res = 0;

    gom->size = 20;
    res = xy_invalid(gom, str);
    cr_assert_eq(res, 0);
}

Test(check_turn_errors, invalid_comma)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "20,2,0";
    int res = check_turn_errors(gom, str);

    cr_assert_eq(res, 84);
}

Test(check_turn_errors, invalid_xy_coordonate)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "20,22";
    int res = 0;

    gom->size = 20;
    res = check_turn_errors(gom, str);
    cr_assert_eq(res, 84);
}

Test(check_turn_errors, invalid_len)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "0,0";
    int res = check_turn_errors(gom, str);

    cr_assert_eq(res, 84);
}

Test(check_turn_errors, invalid_numbers)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "20,a5";
    int res = check_turn_errors(gom, str);

    cr_assert_eq(res, 84);
}

Test(check_turn_errors, valid_input)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char *str = "19,19";
    int res = 0;

    gom->size = 20;
    res = check_turn_errors(gom, str);
    cr_assert_eq(res, 0);
}
