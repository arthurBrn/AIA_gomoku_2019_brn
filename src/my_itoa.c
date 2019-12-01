/*
** EPITECH PROJECT, 2019
** my itoa.c
** File description:
** convert an int to string
*/

#include <global.h>

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char temp;

    while (str[i] != '\0')
        i++;
    i--;
    for (i; i > j; i--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j++;
    }
    return str;
}

char *my_itoa(int nb)
{
    int i = 0;
    char *res = malloc(sizeof(char) * my_intlen(nb) + 1);

    for (i; nb > 9; i++) {
        res[i] = nb % 10 + 48;
        nb /= 10;
    }
    res[i] = nb % 10 + 48;
    res[i+1] = '\0';
    res = my_revstr(res);
    return res;
}
