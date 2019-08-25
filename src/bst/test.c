#include <stdio.h>
#include "bst.h"
#include "assert.h"
#include "../toolkit.h"


int print_node(tree_node_t * node) {
    printf("%d\n", node->value);
    return 0;
}

int main(int argc, char const *argv[])
{
    tree_t tree;

    tree_t * p = &tree;

    tree_init(p);
    
    bst_add_node(p, 0);

    assert(p->root->value == 0);
    bst_add_node(p, 1);
    assert(p->root->right->value == 1);
    bst_add_node(p, -1);
    assert(p->root->left->value == -1);

    bst_add_node(p, 2);
    bst_add_node(p, 3);
    bst_add_node(p, 4);
    bst_add_node(p, 5);
    bst_add_node(p, -3);
    bst_add_node(p, -5);
    bst_add_node(p, -9);
    bst_add_node(p, -10);

    tree_visit(p, print_node);

    assert(is_bst_type(p));

    p->root->left->value = 1111;

    assert(!is_bst_type(p));

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    tree_t * bst = create_bst_from_array(arr, ARRAY_SIZE(arr));

    assert(is_bst_type(bst));

    return 0;
}
