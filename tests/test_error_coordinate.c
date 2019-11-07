/*
** EPITECH PROJECT, 2019
** test_error_coordinate.c
** File description:
** Check if the corrdinate send are correct
*/

#include <criterion/criterion.h>
#include "node_proto.h"

Test(test_coordinate, invalid_first_coordinate)
{
    char *a = "25";
    char *b = "10";
    char *c = "1";
    char **array[3][3];
    int res = 0;

    array[0] = a;
    array[1][0] = b;
    array[2][0] = c;
    res = check_coordinate(array);
    cr_assert_eq(res, 84);
}
