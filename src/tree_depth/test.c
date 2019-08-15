#include "tree_depth.h"
#include "../tree/tree.h"
#include "assert.h"

int main(int argc, char const *argv[])
{
    tree_t tree;
    tree_t * p = &tree;

    tree_init(p);
    
    tree_add_node(p, 5);
    tree_add_node(p, 4);
    tree_add_node(p, 1);
    tree_add_node(p, 2);
    tree_add_node(p, 3);
    tree_add_node(p, 6);
    tree_add_node(p, 7);
    tree_add_node(p, 8);


    int max = max_tree_depth(p->root);
    assert(max == 5);
    int min = min_tree_depth(p->root);
    assert(max == 2);
    return 0;
}
