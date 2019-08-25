#include "../tree/tree.h"

#ifndef BST_H

#define BST_H

int node_add_node(tree_node_t ** tree, tree_node_t * node);


tree_node_t * bst_search(tree_t * tree, int value);

int bst_visit(tree_t * tree, int (*callback)(tree_node_t * node));
int bst_add_node(tree_t * tree, int value);

tree_node_t * bst_search(tree_t * tree, int value);

int is_bst_type(tree_t * tree);

tree_t * create_bst_from_array(int arr[], int size);

#endif