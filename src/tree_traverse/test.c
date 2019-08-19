#include "tree_traverse.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{

    tree_t tree;
    tree_t * p = &tree;

    tree_init(p);

    p->root = node_init(1);

    p->root->left = node_init(2);
    p->root->right = node_init(3);
    p->root->left->left = node_init(4);
    p->root->left->right = node_init(5);
    p->root->right->left = node_init(6);
    p->root->right->right = node_init(7);

    printf("postorder_traverse\n");
    postorder_traverse(p->root);


    printf("preorder_traverse\n");
    preorder_traverse(p->root);


    printf("inorder_traverse\n");
    inorder_traverse(p->root);

    printf("level_traverse\n");
    level_traverse(p->root);
    
    return 0;
}
