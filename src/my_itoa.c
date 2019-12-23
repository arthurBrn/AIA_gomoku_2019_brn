/*
** EPITECH PROJECT, 2019
** my itoa.c
** File description:
** convert an int to string
*/

#include <gomoku.h>

char *itoa(int nb, char *str, int size) {
    str[size] = '\0';
    while (size--) {
        str[size] = (nb % 10) + '0';
        nb = nb / 10;
    }
    return (str);
}