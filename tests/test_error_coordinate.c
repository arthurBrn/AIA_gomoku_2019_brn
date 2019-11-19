/*
** EPITECH PROJECT, 2019
** test_error_coordinate.c
** File description:
** Check if the corrdinate send are correct
*/

#include <criterion/criterion.h>
#include "gomoku.h"

Test(check_coordinate, coordinate_x_invalid)
{
    t_gomoku *gomoku = malloc(sizeof(t_gomoku));
    char *str = "1a,10,1";
    int res = 0;

    gomoku->size=10;
    res = check_coordinate(str, gomoku);
    cr_assert_eq(res, 84);
}

Test(check_coordinate, valid_coordinate)
{
    t_gomoku *gomoku = malloc(sizeof(t_gomoku));
    char *str = "10,10,1";
    int res = 0;

    gomoku->size = 20;
    res = check_coordinate(str, gomoku);;
    cr_assert_eq(res, 1);
}

Test(check_coordinate, invalid_first_coordinate)
{
    t_gomoku *gomoku = malloc(sizeof(t_gomoku));
    char *str = "25,10,1";
    int res = 0;

    gomoku->size=10;
    res = check_coordinate(str, gomoku);
    cr_assert_eq(res, 84);
}
