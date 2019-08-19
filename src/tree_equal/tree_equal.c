#include "../tree/tree.h"
#include "stdlib.h"

int tree_equal(tree_node_t * tree, tree_node_t * tree2 ) {
    if (tree == NULL && tree2 == NULL) {
        return 1;
    }

    if (!tree || !tree2) {
        return 0;
    }

    if (tree->value == tree2->value) {
        return tree_equal(tree->left, tree2->left) && tree_equal(tree->right, tree2->right);
    }

    return 0;
};  