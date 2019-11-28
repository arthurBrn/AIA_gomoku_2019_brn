/*
** EPITECH PROJECT, 2019
** debug_tree.c
** File description:
** Display the tree and all. [used for debug only]
*/

#include "global.h"

void display_node(tree_node_t *node)
{
    if (node->children != NULL) {
    write(1, "REG_NODE ", 9);
    write(1, "[node->x]|[node->y]|[node->pts] ", 32);
    putchar('\n');
    putchar(node->x + '0');
    putchar(node->y + '0');
    putchar(node->points + '0');
    putchar('\n');
    } else {
        write(1, "This node has no children.", 26);
    }
}

void display_root_node()
{
    if (root != NULL) {
        write(1, " ===== ", 7);
        putchar('\n');
        write(1, "ROOT ", 5);
        write(1, " [size] ", 8);
        putchar(root->size + '0');
        display_node(root->node);
        write(1, " ===== ", 7);
        putchar('\n');
        puts("2nd try");
        printf("%d", root->node->children[0]->x + '0');
        putchar('\n');
        printf("%d", root->node->children[0]->y + '0');
        putchar('\n');
        printf("%d", root->node->children[0]->points + '0');
        puts("END 2Nd try");
        display_node(root->node);
        // try here to send not a node but a parent and let's say a depth for later
        for (int cpt = 0; cpt < root->size; cpt++) {
            display_node(root->node->children[cpt]);
        }
    } else
        write(1, "The tree is null", 16);
}