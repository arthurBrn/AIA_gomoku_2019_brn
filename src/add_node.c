/*
** EPITECH PROJECT, 2019
** add_node.c
** File description:
** Will add node to list. Return the head of the list.
*/

#include "node.h"

node_t *add_node(char *str, node_t *head)
{
    node_t *temp = malloc(sizeof(node_t));
    char **tab = my_str_to_word_array(str, ",");

    if (head == NULL) {
        temp->x = atoi(tab[0]);
        temp->y = atoi(tab[1]);
        temp->player = atoi(tab[2]);
        temp->next = NULL;
    }
    if (head != NULL) {
        temp->x = atoi(tab[0]);
        temp->y = atoi(tab[1]);
        temp->player = atoi(tab[2]);
        temp->next = head;
    }
    return (temp);
}
