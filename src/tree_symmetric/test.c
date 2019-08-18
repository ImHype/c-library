#include "tree_symmetric.h"
#include "../tree/tree.h"
#include "assert.h"

int main(int argc, char const *argv[])
{
    tree_t tree;
    tree_t * p = &tree;

    tree_t tree2;
    tree_t * p2 = &tree2;

    tree_init(p);
    
    p->root = node_init(5);
    p->root->left = node_init(1);
    p->root->right = node_init(4);
    
    tree_init(p2);
    
    p2->root = node_init(5);
    p2->root->left = node_init(4);
    p2->root->right = node_init(1);

    assert(tree_symmetric(p->root, p2->root) == 1);

    return 0;
}