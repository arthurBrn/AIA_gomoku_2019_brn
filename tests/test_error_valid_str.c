/*
** EPITECH PROJECT, 2019
** test_error.c
** File description:
** Test the error.c file
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "node_proto.h"

Test(valid_str, test_valid_str_one)
{
    char str[] = {"10,10,1"};
    int res = valid_str(str);

    cr_assert_eq(res, 1);
}

Test(valid_str, test_valid_str_two)
{
    char str[] = {"10,10,2"};
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