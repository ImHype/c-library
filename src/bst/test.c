#include <stdio.h>
#include "bst.h"
#include "assert.h"
#include "../toolkit.h"
#include "stdlib.h"


int print_node(bst_node_t * node) {
    printf("%d\n", node->value);
    return 0;
}

int print(bst_t * bst) {
    tree_visit(bst, print_node);
    printf("------------------------\n");
    return 0;
}

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};


int main(int argc, char const *argv[])
{
    bst_t tree;

    bst_t * p = &tree;

    tree_init(p);
    
    bst_insert(p, 0);

    assert(p->root->value == 0);
    bst_insert(p, 1);
    assert(p->root->right->value == 1);
    bst_insert(p, -1);
    assert(p->root->left->value == -1);

    bst_insert(p, 2);
    bst_insert(p, 3);
    bst_insert(p, 4);
    bst_insert(p, 5);
    bst_insert(p, -3);
    bst_insert(p, -5);
    bst_insert(p, -9);
    bst_insert(p, -10);

    tree_visit(p, print_node);

    assert(is_bst_type(p));

    p->root->left->value = 1111;

    assert(!is_bst_type(p));

    bst_t * bst = malloc(sizeof(bst_t));

    bst_init(bst);

    bst_insert(bst, arr[0]);
    bst_insert(bst, arr[1]);
    bst_insert(bst, arr[2]);

    tree_visit(bst, print_node);
    bst_insert(bst, arr[3]);
    bst_insert(bst, arr[4]);
    bst_insert(bst, arr[5]);

    tree_visit(bst, print_node);

    bst_insert(bst, arr[6]);
    bst_insert(bst, arr[7]);
    tree_visit(bst, print_node);
    bst_insert(bst, arr[8]);
    bst_insert(bst, arr[9]);
    tree_visit(bst, print_node);

    bst_t * bst1 = create_bst_from_array(arr, ARRAY_SIZE(arr));
    assert(is_bst_type(bst1));
    print(bst1);

    for (int i = 0; i < ARRAY_SIZE(arr); i++)
    {
        int value = arr[i];
        bst_remove(bst1, value);
        assert(bst_search(bst1, value) == NULL);
    }
    assert(bst1->root == NULL);
    print(bst1);

    bst_t * bst2 = create_bst_from_array(arr2, ARRAY_SIZE(arr2));
    assert(is_bst_type(bst2));

    for (int i = 0; i < ARRAY_SIZE(arr); i++)
    {
        int value = arr[i];
        bst_remove(bst2, value);
        assert(bst_search(bst2, value) == NULL);
    }
    assert(bst2->root == NULL);
    print(bst2);
    
    return 0;
}
