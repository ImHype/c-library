#include "tree_equal.h"
#include "../tree/tree.h"
#include "assert.h"

int main(int argc, char const *argv[])
{
    tree_t tree;
    tree_t * p = &tree;

    tree_t tree2;
    tree_t * p2 = &tree2;

    tree_init(p);
    
    tree_add_node(p, 5);
    tree_add_node(p, 4);
    tree_add_node(p, 1);
    
    tree_init(p2);
    
    tree_add_node(p2, 5);
    tree_add_node(p2, 4);
    tree_add_node(p2, 1);

    assert(tree_equal(p->root, p2->root) == 1);

    return 0; 
}
