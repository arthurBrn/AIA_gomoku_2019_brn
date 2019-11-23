/*
** EPITECH PROJECT, 2019
** test_error_coordinate.c
** File description:
** Check if the corrdinate send are correct
*/

#include <criterion/criterion.h>
#include "gomoku.h"

Test(check_coordinate, coordinate_x_alpha_invalid)
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

    gomoku->size = 10;
    res = check_coordinate(str, gomoku);;
    cr_assert_eq(res, 1);
}

Test(check_coordinate, invalid_x_coordinate)
{
    t_gomoku *gomoku = malloc(sizeof(t_gomoku));
    char *str = "25,10,1";
    int res = 0;

    gomoku->size=10;
    res = check_coordinate(str, gomoku);
    cr_assert_eq(res, 84);
}

Test(check_coordinate, invalid_y_coordinate)
{
    t_gomoku *gomoku = malloc(sizeof(t_gomoku));
    char *str = "10,25,1";
    int res = 0;

    gomoku->size=10;
    res = check_coordinate(str, gomoku);
    cr_assert_eq(res, 84);
}

Test(check_coordinate, invalid_xy_coordinate)
{
    t_gomoku *gomoku = malloc(sizeof(t_gomoku));
    char *str = "25,22,1";
    int res = 0;

    gomoku->size=20;
    res = check_coordinate(str, gomoku);
    cr_assert_eq(res, 84);
}

Test(check_coordinate, invalid_xy_equal_zero)
{
    t_gomoku *gomoku = malloc(sizeof(t_gomoku));
    char *str = "0,0,1";
    int res = 0;

    gomoku->size=10;
    res = check_coordinate(str, gomoku);
    cr_assert_eq(res, 84);
}

Test(check_coordinate, xy_coordinate_equal_to_board_size)
{
    t_gomoku *gomoku = malloc(sizeof(t_gomoku));
    char *str = "20,20,1";
    int res = 0;

    gomoku->size=20;
    res = check_coordinate(str, gomoku);
    cr_assert_eq(res, 1);
}

Test(check_coordinate, xy_coordinate_equal_to_one)
{
    t_gomoku *gomoku = malloc(sizeof(t_gomoku));
    char *str = "1,1,1";
    int res = 0;

    gomoku->size=10;
    res = check_coordinate(str, gomoku);
    cr_assert_eq(res, 1);
}
