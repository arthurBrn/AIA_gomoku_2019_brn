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

int valid_str(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] < '0' || str[i] > '9' || str[i] != ',')
            return (84);
    return (1);
}

int nbr_coma(char *str)
{
    int j = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ',')
            j++;
    if (j > 2)
        return (84);
    return (1);
}

int check_players(char *str)
{
    if (str[strlen(str)] != "1" || str[strlen(str)] != "2")
        return (84);
    return (1);
}

void invalid_string(void)
{
    puts(ERROR_MSG);
    exit(EXIT_USAGE);
}

int check_string(char *str)
{
    if (valid_str(str) == 84)
        invalid_string();
    if (nbr_coma(str) == 84)
        invalid_string();
    if (check_players(str) == 84)
        invalid_string();
    return (1);
}

char *cut_string(char *str)
{
//    char *str[]
}

void store_board(char *str)
{
    // Create a new node, while keeping the pointer of its head. Hence a double pointer!
    // check si only digit et virgule
    // Check two first digit with map length
    // check 1 and 2 no more than 2 player
    // no more than two coma
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
