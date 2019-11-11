/*
** EPITECH PROJECT, 2019
** test_error.c
** File description:
** Test the error.c file
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "node.h"

Test(check_players, test_player_one)
{
    char str[] = {"10,10,1"};
    int res = check_players(str);

    cr_assert_eq(res, 1);
}

Test(check_players, test_player_two)
{
    char str[] = {"10,10,2"};
    int res = check_players(str);

    cr_assert_eq(res, 1);
}

Test(check_players, test_w_wrong_player)
{
    char str[] = {"10,10,4"};
    int res = check_players(str);

    cr_assert_eq(res, 84);
}
