/*
** EPITECH PROJECT, 2019
** tree.h
** File description:
** Will contain the structure used for the tree
*/

#ifndef _TREE_H_
#define _TREE_H_

#include "gomoku.h"
#define DEPTH_SIZE 1

typedef struct tree_node
{
    struct tree_node *parent;
    int x;
    int y;
    int points;
    struct tree_node **children;
}tree_node_t;

typedef struct root
{
    tree_node_t *node;
    int size;
    int depth;
}root_t;

int initialize_tree(t_gomoku *gomoku);
root_t *adding_one_depth(root_t *root, tree_node_t *parent ,t_gomoku *gom);
root_t *init_root_node(root_t *root, t_gomoku *gom);
tree_node_t *init_regular_node(tree_node_t *parent, tree_node_t *reg_node, int value);
void display_root_node();
void display_node(tree_node_t *node);
#endif
