/*
** EPITECH PROJECT, 2019
** test_error.c
** File description:
** Test the error.c file
*/

#include <criterion/criterion.h>
#include "gomoku.h"

Test(nbr_coma, str_starting_by_coma)
{
    char str[] = {",101,01"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 84);
}

Test(nbr_coma, str_ending_by_coma)
{
    char str[] = {"1,0101,"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 84);
}

Test(nbr_coma, coma_followed_by_coma)
{
    char str[] = {"1,01,,01"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 84);
}

Test(nbr_coma, coma_preceeded_by_coma)
{
    char str[] = {"1,01,,,01"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 84);
}

Test(nbr_coma, test_with_only_one_coma)
{
    char str[] = {"10,101"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 84);
}

Test(nbr_coma, test_with_three_coma)
{
    char str[] = {"1,0,1,01"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 84);
}

Test(nbr_coma, test_with_no_coma)
{
    char str[] = {"10101"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 84);
}

Test(nbr_coma, test_str_w_two_coma)
{
    char str[] = {"10,10,1"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 1);
}
