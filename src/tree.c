/*
** EPITECH PROJECT, 2019
** tree.c
** File description:
** Will contain every function related to rooted tree
*/

#include "global.h"

/**
 * We'll have to adapt our code to the depth
 * The first depth we've done. BUT
 * We have to adapt the entire code to the depth stocked in DEPTH_SIZE
 * Let's do that
 * 
 * We have our main root node, initialized through init_root_node which return us a root node init w/ :
 *  - size
 *  - tree_node_t struct *node
 *  - *node->parent pointing to null
 *  - *node->children being malloc as a pointer toward an array of pointer
 *  - *node->xypoints set to 0 before the value would be set.
 * 
 * NOW we need to recreate this parten for regular node as well if DEPTH_SIZE is greater than 1
 * */



tree_node_t *init_regular_node(tree_node_t *parent, tree_node_t *reg, int value)
{
    reg->parent = parent;
    reg->x = value;
    reg->y = value;
    reg->points = value;
    if (DEPTH_SIZE == 1)
        reg->children = NULL;
    // Else we call a function to malloc ?
    
    return (reg);
}

root_t *adding_one_depth(root_t *root_node, tree_node_t *parent, t_gomoku *gom)
{
    tree_node_t *reg_node = NULL;
    int value = 0;

    for (int i = 0; i < root_node->size; i++) {
        reg_node = malloc(sizeof(tree_node_t));
        reg_node = init_regular_node(parent, reg_node, value);
        //root_node->node->children[i] = reg_node;
        parent->children[i] = reg_node;
        value++;
    }
    return (root_node);
}

root_t *init_root_node(root_t *root_node, t_gomoku *gom)
{
    root_node->size = ((gom->size * gom->size) - list_length(head));
    root_node->depth = DEPTH_SIZE;
    root_node->node = malloc(sizeof(tree_node_t));
    root_node->node->parent = NULL;
    root_node->node->x = 0;
    root_node->node->y = 0;
    root_node->node->points = 0;
    root_node->node->children = (tree_node_t **)malloc(sizeof(tree_node_t *) * root_node->size);
    return (root_node);
}

int initialize_tree(t_gomoku *gom)
{
    tree_node_t *parent = NULL;
    root_t *temp_root = NULL;

    // We start by creating the root node
    temp_root = malloc(sizeof(root_t));
    temp_root = init_root_node(temp_root, gom);
    
    // Then we add the depth with the children and them pointing to the rigth parents
    for (int i = 0; i < DEPTH_SIZE; i++) {
        parent = malloc(sizeof(tree_node_t));
        // if we're at the first iteration, we're at the first depth, and so we want our parent
        // to be the main root ndoe
        if (i == 0)
            parent = temp_root->node;
        //else
          //  parent =        
        temp_root = adding_one_depth(temp_root, parent, gom);
    }
    root = temp_root;
}