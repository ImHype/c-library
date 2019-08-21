#include "tree_recovery.h"
#include "../toolkit.h"
#include "../tree_traverse/tree_traverse.h"
#include "stdio.h"


int main(int argc, char const *argv[])
{
    int preorder[] = {1,2,4,5,3,6,7};
    int inorder[] = {4,2,5,1,6,3,7};

    tree_t tree;
    tree_t * treep = &tree;

    tree_init(treep);

    preorder_inorder_tree_recovery(preorder, inorder, ARRAY_SIZE(inorder), &treep->root);

    printf("preorder_traverse\n");
    preorder_traverse(treep->root);

    printf("inorder_traverse\n");
    inorder_traverse(treep->root);

    return 0;
}
