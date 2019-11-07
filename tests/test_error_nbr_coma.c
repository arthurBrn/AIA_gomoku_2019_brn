/*
** EPITECH PROJECT, 2019
** test_error.c
** File description:
** Test the error.c file
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "node_proto.h"

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

Test(nbr_coma, test_with_no_coma)
{
    char str[] = {"10101"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 84);
}

Test(nbr_coma, test_with_three_coma)
{
    char str[] = {"1,0,1,01"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 84);
}

Test(nbr_coma, test_with_coma_next_to_coma)
{
    char str[] = {"1,01,,01"};
    int res = nbr_coma(str);

    cr_assert_eq(res, 84);
}
