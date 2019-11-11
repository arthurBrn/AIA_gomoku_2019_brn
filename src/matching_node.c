/*
** EPITECH PROJECT, 2019
** matching_node
** File description:
** Return 1 if the string passed in parameter matched 
** one of the existing nodes.
*/

#include "node.h"

int matching_node(char *str, node_t *head)
{
    char **tab = my_str_to_word_array(str, ",");
    int x = atoi(tab[0]);
    int y = atoi(tab[1]);
    int p = atoi(tab[2]);
    int flag = 0;

    if (head == NULL)
        return (0);
    while (head != NULL) {
        if (x == head->x && y == head->y && p == head->player)
            flag = 1;
        head = head->next;
    }
    return (flag);
}
