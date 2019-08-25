#include "bst.h"
#include "../tree/tree.h"
#include "stdlib.h"


tree_node_t * node_search(tree_node_t ** tree, int value) {
    tree_node_t * p = *tree;

    if (p == NULL) {
        return NULL;
    }

    if (p->value == value) {
        return p;
    }

    if (value < p->value) {
        return node_search(&p->left, value);
    }

    return node_search(&p->right, value);
};


int node_add_node(tree_node_t ** tree, tree_node_t * node) {
    tree_node_t * p = *tree;
    if (p == NULL) {
        *tree = node;
        return 0;
    }

    if (node->value < p->value) {
        return node_add_node(&p->left, node);
    }

    return node_add_node(&p->right, node);
};

int is_bst_node(tree_node_t * tree) {
    if (!tree || !tree->left || !tree->right) {
        return 1;
    }

    return (tree->left->value < tree->value && tree->right->value > tree->value) && is_bst_node(tree->left) && is_bst_node(tree->right);
};


int bst_init(tree_t * tree) {
    return tree_init(tree);
}

tree_node_t * bst_search(tree_t * tree, int value) {
    return node_search(&tree->root, value);
};


int bst_add_node(tree_t * tree, int value) {
    return node_add_node(&tree->root, node_init(value));;
};


int is_bst_type(tree_t * tree) {
    return is_bst_node(tree->root);
};


tree_t * create_bst_from_array(int arr[], int size) {
    tree_t * tree = malloc(sizeof(tree_t));

    tree_init(tree);

    for (int i = 0; i < size; i++)
    {
        bst_add_node(tree, arr[i]);
    }

    return tree;
}