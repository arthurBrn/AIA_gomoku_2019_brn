/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** Contains all function for free tabs / structure / linked_list
*/

#include "global.h"

void free_list(node_t *node_head)
{
    node_t *current = NULL;
    node_t *next = NULL;

    while (node_head != NULL) {
        current = node_head;
        next = node_head->next;
        node_head = next;
        free(current);
    }
    head = NULL;
}
