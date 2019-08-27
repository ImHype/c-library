#include "tree.h"
#include "stdlib.h"

tree_node_t * node_init(int value) {
    tree_node_t * node = malloc(sizeof(tree_node_t));

    node->left = NULL;
    node->right = NULL;
    node->value = value;
    node->height = 0;

    return node;
};

int node_visit(tree_node_t ** tree, int (*callback)(tree_node_t * node)) {
    tree_node_t * p = *tree;

    if (p == NULL) {
        return 0;
    }

    node_visit(&p->left, callback);

    callback(p);

    node_visit(&p->right, callback);

    return 0;
};

int tree_init(tree_t * tree) {
    tree->root = NULL;
    return 0;
}

int tree_visit(tree_t * tree, int (*callback)(tree_node_t * node)) {
    return node_visit(&tree->root, callback);
};
