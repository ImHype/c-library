#include <stdio.h>
#include "tree.h"
#include "assert.h"


int print_node(tree_node_t * node) {
    printf("%d\n", node->value);
    return 0;
}

int main(int argc, char const *argv[])
{
    tree_t tree;

    tree_t * p = &tree;

    tree_init(p);
    
    p->root = node_init(0);

    assert(p->root->value == 0);

    p->root->right = node_init(1);

    assert(p->root->right->value == 1);
    
    p->root->left = node_init(-1);

    assert(p->root->left->value == -1);

    p->root->left->left = node_init(2);
    p->root->left->right = node_init(3);

    p->root->right->left = node_init(4);
    p->root->right->right = node_init(4);

    p->root->left->left->left = node_init(-3);
    p->root->left->left->right = node_init(-5);

    tree_visit(p, print_node);

    return 0;
}
