/*
** EPITECH PROJECT, 2019
** test_error.c
** File description:
** Test the error.c file
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "node.h"

Test(check_string, test_invalid_coma_count)
{
    char str[] = {"10,104"};
    int res = check_string(str);

    cr_assert_eq(res, 84);
}

Test(check_string, test_invalid_string)
{
    char str[] = {"10104"};
    int res = check_string(str);

    cr_assert_eq(res, 84);
}

Test(check_string, test_invalid_players)
{
    char str[] = {"10,10,4"};
    int res = check_string(str);

    cr_assert_eq(res, 84);
}

Test(check_string, test_valid_string)
{
    char str[] = {"10,10,1"};
    int res = check_string(str);

    cr_assert_eq(res, 1);
}
