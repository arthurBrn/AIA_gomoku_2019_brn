/*
** EPITECH PROJECT, 2019
** list_length.c
** File description:
** Return the length of the string
*/

#include "node.h"

int list_length(node_t *head)
{
    int i = 0;

    for (i; head != NULL; i++)
        head = head->next;
    return (i);
}
