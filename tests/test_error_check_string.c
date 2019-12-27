/*
** EPITECH PROJECT, 2019
** test_error.c
** File description:
** Test the error.c file
*/

#include <criterion/criterion.h>
#include "gomoku.h"

Test(check_string, test_invalid_coma_count)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char str[] = {"10,104"};

    gom->size = 20;
    gom->start = 1;
    cr_assert_eq(check_string(str, gom), MY_EXIT_FAILURE);
}

Test(check_string, test_invalid_string)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char str[] = {"10104"};

    gom->size = 20;
    gom->start = 1;
    cr_assert_eq(check_string(str, gom), MY_EXIT_FAILURE);
}

Test(check_string, test_invalid_players)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char str[] = {"10,10,4"};

    gom->size = 20;
    gom->start = 1;
    cr_assert_eq(check_string(str, gom), MY_EXIT_FAILURE);
}

Test(check_string, test_valid_string)
{
    t_gomoku *gom = malloc(sizeof(t_gomoku));
    char str[] = {"10,10,1"};

    gom->size = 20;
    gom->start = 1;
    cr_assert_eq(check_string(str, gom), 1);
}