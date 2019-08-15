#include "../tree/tree.h"
#include "stdlib.h"

int max_tree_depth(node_t * tree) {
    if (tree == NULL) {
        return 0;
    }

    int left_depth = max_tree_depth(tree->left);
    int right_depth = max_tree_depth(tree->right);

    return (left_depth > right_depth ? left_depth: right_depth) + 1;
};


int min_tree_depth(node_t * tree) {
    if(tree == NULL)
        return 0;
    if(tree->left == NULL || tree->right == NULL)
        return 1;

    int left_depth = min_tree_depth(tree->left);
    int right_depth = min_tree_depth(tree->right);


    return left_depth < right_depth ? (left_depth + 1) : (right_depth + 1);
}