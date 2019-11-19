/*
** EPITECH PROJECT, 2019
** test_error.c
** File description:
** Test the error.c file
*/

#include <criterion/criterion.h>
#include "gomoku.h"

Test(only_digit_str, test_good_nbr_of_coma)
{
    char str[] = {"10,10,,1"};
    int res = only_digit_str(str);

    cr_assert_eq(res, 84);
}

Test(only_digit_str, test_without_coma)
{
    char str[] = {"10101"};
    int res = only_digit_str(str);

    cr_assert_eq(res, 84);
}

Test(only_digit_str, test_with_non_digit_char)
{
    char str[] = {"10,a10,1"};
    int res = only_digit_str(str);

    cr_assert_eq(res, 84);
}

Test(only_digit_str, test_valid_str_one)
{
    char str[] = {"10,10,1"};
    int res = only_digit_str(str);

    cr_assert_eq(res, 1);
}
