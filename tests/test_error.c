/*
** EPITECH PROJECT, 2019
** test_error.c
** File description:
** Test the error.c file
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "node_proto.h"

Test(valid_str, test_valid_str)
{
    char str[] = {"10,10,1"};
    int res = valid_str(str);

    cr_assert_eq(res, 1);
}

Test(valid_str, test_without_coma)
{
    char str[] = {"10101"};
    int res = valid_str(str);

    cr_assert_eq(res, 84);
}

Test(valid_str, test_with_non_digit_char)
{
    char str[] = {"10,a10,1"};
    int res = valid_str(str);

    cr_assert_eq(res, 84);
}

Test(nbr_coma, test_str_w_two_coma)
{
    char str[] = {"10,10,1"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 1);
}

Test(nbr_coma, test_with_only_one_coma)
{
    char str[] = {"10,101"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 84);
}

Test(check_players, test_player_one)
{
    char str[] = {"10,101"};
    int res = check_players(str);

    cr_assert_eq(res, 1);
}

Test(check_players, test_player_two)
{
    char str[] = {"10,102"};
    int res = check_players(str);

    cr_assert_eq(res, 1);
}

Test(check_players, test__w_wrong_player)
{
    char str[] = {"10,104"};
    int res = check_players(str);

    cr_assert_eq(res, 84);
}
