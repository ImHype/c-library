#include "../tree/tree.h"
#include "../linked_list/linked_list.h"
#include "stdio.h"

int postorder_traverse(tree_node_t * node) {
    if (node == NULL) {
        return 0;
    }

    postorder_traverse(node->left);
    postorder_traverse(node->right);

    printf("%d\n", node->value);

    return 0;
}


int preorder_traverse(tree_node_t * node) {
    if (node == NULL) {
        return 0;
    }

    printf("%d\n", node->value);

    preorder_traverse(node->left);
    preorder_traverse(node->right);

    return 0;
}


int inorder_traverse(tree_node_t * node) {
    if (node == NULL) {
        return 0;
    }

    inorder_traverse(node->left);

    printf("%d\n", node->value);

    inorder_traverse(node->right);

    return 0;
}


int level_traverse(tree_node_t * node) {
    linked_list_t list;
    linked_list_t * p = &list;

    create_linked_list(p);

    linked_list_add(p, node);

    while (!linked_list_is_empty(p))
    {
        tree_node_t * node = linked_list_shift(p);

        printf("%d\n", node->value);

        if (node->left != NULL) {
            linked_list_add(p, node->left);
        }

        if (node->right != NULL) {
            linked_list_add(p, node->right);
        }
    }
    
    return 0;
}