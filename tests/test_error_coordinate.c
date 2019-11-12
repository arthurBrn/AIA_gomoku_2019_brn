/*
** EPITECH PROJECT, 2019
** test_error_coordinate.c
** File description:
** Check if the corrdinate send are correct
*/

#include <criterion/criterion.h>
#include "gomoku.h"

Test(test_coordinate, valid_coordinate)
{
    t_gomoku *gomoku = malloc(sizeof(*gomoku));
    gomoku->size=10;
    char *str = "10,10,1";
    int res = check_coordinate(str, gomoku);

    cr_assert_eq(res, 1);
}

Test(test_coordinate, invalid_first_coordinate)
{
    t_gomoku *gomoku = malloc(sizeof(*gomoku));
    gomoku->size=10;
    char *str = "25,10,1";
    int res = check_coordinate(str, gomoku);

    cr_assert_eq(res, 84);
}
