/*
** EPITECH PROJECT, 2019
** test_error.c
** File description:
** Test the error.c file
*/

#include <criterion/criterion.h>
#include "gomoku.h"

Test(check_players, test_player_one)
{
    char str = '1';
    int res = check_players(str);

    cr_assert_eq(res, 1);
}

Test(check_players, test_player_two)
{
    char str = '2';
    int res = check_players(str);

    cr_assert_eq(res, 1);
}

Test(check_players, test_player_three)
{
    char str = '3';
    int res = check_players(str);

    cr_assert_eq(res, 1);
}

Test(check_players, test_w_wrong_player)
{
    char str = '4';
    int res = check_players(str);

    cr_assert_eq(res, 84);
}

Test(check_players, test_w_wrong_char)
{
    char str = 'a';
    int res = check_players(str);

    cr_assert_eq(res, 84);
}

