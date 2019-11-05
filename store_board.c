/*
** EPITECH PROJECT, 2019
** store_board.c
** File description:
** linked list to store board input
*/

#include "node_proto.h"
#include "node.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

void store_board(char *str)
{
    // We might need to store the address of the head
    // of the linked list in a structure.
    if (check_string(str) == 1) {
        // recup la string ici
        create_node(x, y, player);
    }
}

linked_list_t create_node(char *x, char *y, char *player)
{
    int index = 0;
    linked_list_t *element = NULL;
    linked_list_t *temp = NULL;

    element = malloc(sizeof(linked_list_t));
    element->data_x = atoi(x);
    element->data_y = atoi(y);
    element->player = atoi(player);
    element->next = temp;
    temp = element;
    return (element);
}
