/*
** EPITECH PROJECT, 2019
** test_utils.c
** File description:
** Test the function int isnum(char *str);
*/

#include "gomoku.h"
#include <criterion/criterion.h>

Test(isnum, str_w_chars)
{
    char *str = "a2b3";
    int res = isnum(str);

    cr_assert_eq(res, 84);
}

Test(isnum, str_w_space)
{
    char *str = "123 456";
    int res = isnum(str);

    cr_assert_eq(res, 84);
}

Test(isnum, str_w_char_and_space)
{
    char *str = "2b3 456";
    int res = isnum(str);

    cr_assert_eq(res, 84);
}

Test(isnum, invalid_str)
{
    char *str = "azerty";
    int res = isnum(str);

    cr_assert_eq(res, 84);
}

Test(isnum, valid_str)
{
    char *str = "123456789";
    int res = isnum(str);

    cr_assert_eq(res, 0);
}

Test(isnum, valid_str_zero)
{
    char *str = "0";
    int res = isnum(str);

    cr_assert_eq(res, 0);
}

